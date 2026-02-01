import PyPDF2
import os
import glob

def extract_text_from_pdf(pdf_path):
    """Extract text from a PDF file"""
    text = ""
    try:
        with open(pdf_path, 'rb') as file:
            pdf_reader = PyPDF2.PdfReader(file)
            for page in pdf_reader.pages:
                text += page.extract_text() + "\n"
    except Exception as e:
        return f"Error reading {pdf_path}: {str(e)}"
    return text

def main():
    # Get all ITN PDF files
    pdf_files = sorted(glob.glob("ITN_*.pdf"))
    
    summaries = {}
    
    for pdf_file in pdf_files:
        print(f"Processing {pdf_file}...")
        text = extract_text_from_pdf(pdf_file)
        # Save extracted text to a temporary file for AI processing
        with open(f"{pdf_file}_extracted.txt", "w", encoding="utf-8") as f:
            f.write(text)
        summaries[pdf_file] = len(text)
        print(f"  Extracted {len(text)} characters from {pdf_file}")
    
    print(f"\nExtracted text from {len(pdf_files)} PDF files.")
    print("Text files saved for summarization.")

if __name__ == "__main__":
    main()
