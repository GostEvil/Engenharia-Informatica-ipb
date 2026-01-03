PIPES AND FIFOS

This chapter describes pipes and FIFOs. Pipes are the oldest method of IPC on the UNIX system, having appeared in Third Edition UNIX in the early 1970s. Pipes provide an elegant solution to a frequent requirement: having created two processes to run different programs (commands), how can the shell allow the output produced by one process to be used as the input to the other process? Pipes can be used to pass data between related processes (the meaning of related will become clear later). FIFOs are a variation on the pipe concept. The important difference is that FIFOs can be used for communication between any processes.

44. 1 Overview

Every user of the shell is familiar with the use of pipes in commands such as the following, which counts the number of files in a directory:

$ Is I wc -1

In order to execute the above command, the shell creates two processes, executing Is and wc, respectively. (This is done using and exec(), which are described in Chapters 24 and 27.) Figure 44-1 shows how the two processes employ the pipe.

Among other things. Figure 44-1 is intended to illustrate how pipes got their name. We can think of a pipe as a piece of plumbing that allows data to flow from one process to another.

One point to note in Figure 44-1 is that the two processes are connected to the pipe so that the writing process {Is) has its standard output (file descriptor 1) joined to the write end of the pipe, while the reading process {wc) has its standard input (file descriptor 0) joined to the read end of the pipe. In effect, these two processes are unaware of the existence of the pipe; they just read from and write to the standard file descriptors. The shell must do some work in order to set things up in this way, and we see how this is done in Section 44.4.

In the following paragraphs, we cover a number of important characteristics of pipes.

A pipe is a byte stream

When we say that a pipe is a byte stream, we mean that there is no concept of messages or message boundaries when using a pipe. The process reading from a pipe can read blocks of data of any size, regardless of the size of blocks written by the writing process. Furthermore, the data passes through the pipe sequentially— bytes are read from a pipe in exactly the order they were written. It is not possible to randomly access the data in a pipe using lseek().

If we want to implement the notion of discrete messages in a pipe, we must do this within our application. While this is feasible (refer to Section 44.8), it may be preferable to use alternative IPC mechanisms, such as message queues and datagram sockets, which we discuss in later chapters.

Reading fram a pipe

Attempts to read from a pipe that is currently empty block until at least one byte has been written to the pipe. If the write end of a pipe is closed, then a process reading from the pipe will see end-of-file (i.e., read() returns 0) once it has read all remaining data in the pipe.

Pipes are unidirectianal

Data can travel only in one direction through a pipe. One end of the pipe is used for writing, and the other end is used for reading.

On some other UNIX implementations— notably those derived from System V Release 4— pipes are bidirectional (so-called stream pipes). Bidirectional pipes are not specified by any UNIX standards, so that, even on implementations where they are provided, it is best to avoid reliance on their semantics. As an alternative, we can use UNIX domain stream socket pairs (created using the socketpairQ system call described in Section 57.5), which provide a standardized bidirectional communication mechanism that is semantically equivalent to stream pipes.

890

Writes of up to PIPE BUF bytes ore guaranteed to be atomic

If multiple processes are writing to a single pipe, then it is guaranteed that their data won’t be intermingled if they write no more than PIPE_BUF bytes at a time.

SUSvS requires that PIPE_BUF be at least _POSIX_PIPE_BUF (512). An implementation should define PIPE_BUF (in <limits.h>) and/or allow the call fpathconf(fd, _PC_PIPE_BUF) to return the actual upper limit for atomic writes. PIPE_BUF varies across UNIX implementations; for example, it is 512 bytes on FreeBSD 6.0, 4096 bytes on Tru64 5.1, and 5120 bytes on Solaris 8. On Linux, PIPE_BUF has the value 4096.

When writing blocks of data larger than PIPE_BUF bytes to a pipe, the kernel may transfer the data in multiple smaller pieces, appending further data as the reader removes bytes from the pipe. (The write() call blocks until all of the data has been written to the pipe.) When there is only a single process writing to a pipe (the usual case), this doesn’t matter. However, if there are multiple writer processes, then writes of large blocks may be broken into segments of arbitrary size (which may be smaller than PIPE_BUF bytes) and interleaved with writes by other processes.

The PIPE_BUF limit affects exactly when data is transferred to the pipe. When writing up to PIPE_BUF bytes, write() will block if necessary until sufficient space is available in the pipe so that it can complete the operation atomically. When more than PIPE_BUF bytes are being written, write() transfers as much data as possible to fill the pipe, and then blocks until data has been removed from the pipe by some reading process. If such a blocked write() is interrupted by a signal handler, then the call unblocks and returns a count of the number of bytes successfully transferred, which will be less than was requested (a so-called write).

On Linux 2.2, pipe writes of any size are atomic, unless interrupted by a signal handler. On Linux 2.4 and later, any write greater than PIPE BUF bytes may be interleaved with writes by other processes. (The kernel code implementing pipes underwent substantial changes between kernel versions 2.2 and 2.4.)

Pipes hove o limited capacity

A pipe is simply a buffer maintained in kernel memory. This buffer has a maximum capacity. Once a pipe is full, further writes to the pipe block until the reader removes some data from the pipe.

SUSvS makes no requirement about the capacity of a pipe. In Linux kernels before 2.6.11, the pipe capacity is the same as the system page size (e.g., 4096 bytes on x86-32); since Linux 2.6.11, the pipe capacity is 65,536 bytes. Other UNIX implementations have different pipe capacities.

In general, an application never needs to know the exact capacity of a pipe. If we want to prevent the writer process(es) from blocking, the process(es) reading from the pipe should be designed to read data as soon as it is available.

In theory, there is no reason why a pipe couldn’t operate with smaller capacities, even with a single-byte buffer. The reason for employing large buffer sizes is efficiency: each time a writer fills the pipe, the kernel must perform a context switch to allow the reader to be scheduled so that it can empty some data from the pipe. Employing a larger buffer size means that fewer context switches are required.

Starting with Linux 2.6.35, the capacity of a pipe can be modified. The Linux-specific call fcntl(fd, F_SETPIPE_SZ, size) changes the capacity of the pipe referred to by fd to be at least size bytes. An unprivileged process can change the pipe capacity to any value in the range from the system page size up to the value in /proc/sys/fs/pipe-max-size. The default value for pipe-maxsize is 1,048,576 bytes. A privileged (CAP SYS RESOURCE) process can override this limit. When allocating space for the pipe, the kernel may round size up to some value convenient for the implementation. Thefcntl(fd, F_GETPIPE_SZ) call returns the actual size allocated for the pipe

44.2 Creating and Using Pipes

The pipe() system call creates a new pipe.

#include <unistd.h> int pipe(int filedes[2]) ■,

Returns 0 on success, or -1 on error

A successful call to pipe( ) returns two open file descriptors in the array filedes: one for the read end of the pipe {filedes[0]) and one for the write end {filedes[l]).

As with any file descriptor, we can use the read() and write() system calls to perform 1/ O on the pipe. Once written to the write end of a pipe, data is immediately available to be read from the read end. A read() from a pipe obtains the lesser of the number of bytes requested and the number of bytes currently available in the pipe (but blocks if the pipe is empty).

We can also use the stdio functions {printfO, scanfi), and so on) with pipes by first using fdopenO to obtain a file stream corresponding to one of the descriptors in filedes (Section 13.7). However, when doing this, we must be aware of the stdio buffering issues described in Section 44.6.

The call ioctl(fd, FIONREAD, &cnt) returns the number of unread bytes in the pipe or FIFO referred to by the file descriptor/d. This feature is also available on some other implementations, but is not specified in SUSvS.

Figure 44-2 shows the situation after a pipe has been created by pipe(), with the calling process having file descriptors referring to each end.

Figure 44-2: Process file descriptors after creating a pipe

A pipe has few uses within a single process (we consider one in Section 63.5.2). Normally, we use a pipe to allow communication between two processes. To connect two processes using a pipe, we follow the pipe() call with a call to fork(). During a fork(), the child process inherits copies of its parent’s file descriptors (Section 24.2.1), bringing about the situation shown on the left side of Figure 44-3.

Figure 44-3: Setting up a pipe to transfer data from a parent to a child

While it is possible for the parent and child to both read from and write to the pipe, this is not usual. Therefore, immediately after the fork(), one process closes its descriptor for the write end of the pipe, and the other closes its descriptor for the read end. For example, if the parent is to send data to the child, then it would close its read descriptor for the pipe, filedes[0], while the child would close its write descriptor for the pipe, filedes[ 1 ], bringing about the situation shown on the right side of Figure 44-3. The code to create this setup is shown in Listing 44-1.

Listing 44-1: Steps in creating a pipe to transfer data from a parent to a child

int filedes[2];

if (pipe(filedes) == -l) /* Create the pipe */

errExit("pipe");

switch (forkO) { /* Create a child process */

case -1:

errExit("fork"); case 0: /* Child */

if (close(filedes[l] ) == -l) /* Close unused write end */

errExit("close");

/* Child now reads from pipe */ break;

default: /* Parent */

if (close(filedes[0] ) == -l) /* Close unused read end */

errExit("close");

/* Parent now writes to pipe */ break;

}

One reason that it is not usual to have both the parent and child reading from a single pipe is that if two processes try to simultaneously read from a pipe, we can’t

be sure which process will be the first to succeed— the two processes race for data. Preventing such races would require the use of some synchronization mechanism. However, if we require bidirectional communication, there is a simpler way: just create two pipes, one for sending data in each direction between the two processes. (If employing this technique, then we need to be wary of deadlocks that may occur if both processes block while trying to read from empty pipes or while trying to write to pipes that are already full.)

While it is possible to have multiple processes writing to a pipe, it is typical to have only a single writer. (We show one example of where it is useful to have multiple writers to a pipe in Section 44.3.) By contrast, there are situations where it can be useful to have multiple writers on a FIFO, and we see an example of this in Section 44.8.

Starting with kernel 2.6.27, Linux supports a new, nonstandard system call, pipe2(). This system call performs the same task as pipe(), but supports an additional argument, flags, that can be used to modify the behavior of the system call. Two flags are supported. The O CLOEXEC flag causes the kernel to enable the close-on-exec flag (FD CLOEXEC) for the two new file descriptors. This flag is useful for the same reasons as the open() O CLOEXEC flag described in Section 4.3.1. The O NONBLOCK flag causes the kernel to mark both underlying open file descriptions as nonblocking, so that future 1/ O operations will be nonblocking. This saves additional calls to fcntl() to achieve the same result.

Pipes allow communication between related processes

In the discussion so far, we have talked about using pipes for communication between a parent and a child process. However, pipes can be used for communication between any two (or more) related processes, as long as the pipe was created by a common ancestor before the series of fork() calls that led to the existence of the processes. (This is what we meant when we referred to related processes at the beginning of this chapter.) For example, a pipe could be used for communication between a process and its grandchild. The first process creates the pipe, and then forks a child that in turn forks to yield the grandchild. A common scenario is that a pipe is used for communication between two siblings— their parent creates the pipe, and then creates the two children. This is what the shell does when building a pipeline.

There is an exception to the statement that pipes can be used to communicate only between related processes. Passing a file descriptor over a UNIX domain socket (a technique that we briefly describe in Section 61.13.3) makes it possible to pass a file descriptor for a pipe to an unrelated process.

Closing unused pipe file descriptors

Closing unused pipe file descriptors is more than a matter of ensuring that a process doesn’t exhaust its limited set of file descriptors— it is essential to the correct use of pipes. We now consider why the unused file descriptors for both the read and write ends of the pipe must be closed.

The process reading from the pipe closes its write descriptor for the pipe, so that, when the other process completes its output and closes its write descriptor, the reader sees end-of-file (once it has read any outstanding data in the pipe).

If the reading process doesn’t close the write end of the pipe, then, after the other process closes its write descriptor, the reader won’t see end-of-file, even after

894

it has read all data from the pipe. Instead, a read() would block waiting for data, because the kernel knows that there is still at least one write descriptor open for the pipe. That this descriptor is held open by the reading process itself is irrelevant; in theory, that process could still write to the pipe, even if it is blocked trying to read. For example, the read() might be interrupted by a signal handler that writes data to the pipe. (This is a realistic scenario, as we’ll see in Section 63.5.2.)

The writing process closes its read descriptor for the pipe for a different reason. When a process tries to write to a pipe for which no process has an open read descriptor, the kernel sends the SIGPIPE signal to the writing process. By default, this signal kills a process. A process can instead arrange to catch or ignore this signal, in which case the write() on the pipe fails with the error EPIPE (broken pipe). Receiving the SIGPIPE signal or getting the EPIPE error is a useful indication about the status of the pipe, and this is why unused read descriptors for the pipe should be closed.

Note that the treatment of a write() that is interrupted by a SIGPIPE handler is special. Normally, when a write() (or other “slow” system call) is interrupted by a signal handler, the call is either automatically restarted or fails with the error EINTR, depending on whether the handler was installed with the sigaction() SA RESTART flag (Section 21.5). The behavior in the case of SIGPIPE is different because it makes no sense either to automatically restart the write() or to simply indicate that the write() was interrupted by a handler (thus implying that the write() could usefully be manually restarted). In neither case can a subsequent write() attempt succeed, because the pipe will still be broken.

If the writing process doesn’t close the read end of the pipe, then, even after the other process closes the read end of the pipe, the writing process will still be able to write to the pipe. Eventually, the writing process will fill the pipe, and a further attempt to write will block indefinitely.

One final reason for closing unused file descriptors is that it is only after all file descriptors in all processes that refer to a pipe are closed that the pipe is destroyed and its resources released for reuse by other processes. At this point, any unread data in the pipe is lost.

Example program

The program in Listing 44-2 demonstrates the use of a pipe for communication between parent and child processes. This example demonstrates the byte-stream nature of pipes referred to earlier— the parent writes its data in a single operation, while the child reads data from the pipe in small blocks.

The main program calls pipe() to create a pipe ©, and then calls fork() to create a child ®. After the fork(), the parent process closes its file descriptor for the read end of the pipe ®, and writes the string given as the program’s command-line argument to the write end of the pipe ®. The parent then closes the read end of the pipe ®, and calls wait() to wait for the child to terminate ®. After closing its file descriptor for the write end of the pipe ®, the child process enters a loop where it reads ® blocks of data (of up to BUE_SIZE bytes) from the pipe and writes ® them to standard output. When the child encounters end-of-file on the pipe ®, it exits the loop @, writes a trailing newline character, closes its descriptor for the read end of the pipe, and terminates

