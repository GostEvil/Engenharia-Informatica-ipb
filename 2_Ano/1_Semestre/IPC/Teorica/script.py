import os
import PyPDF2

base_dir = r"C:\Users\nunos\EI-ipb-Pasta_Partilhada\2_Ano\1_Semestre\IPC\Teorica"

pdf_files = [
    "1-Introdução1.pdf",
    "2-Os Humanos.pdf",
    "3-Os Computadores.pdf",
    "4-A Engenharia da Usabilidade.pdf",
    "5-Análise.pdf",
    "6-Desenho.pdf",
    "7-Principios e Prática.pdf",
    "8-Avaliação de Usabilidade.pdf",
    "Testes de Usabilidade exigência supérflua ou necessidade.pdf",
]

output_txt = os.path.join(base_dir, "arquivo.txt")

with open(output_txt, "w", encoding="utf-8") as txt_out:
    for filename in pdf_files:
        pdf_path = os.path.join(base_dir, filename)
        if not os.path.exists(pdf_path):
            # se o ficheiro não existir, passa à frente
            continue

        with open(pdf_path, "rb") as pdffileobj:
            pdfreader = PyPDF2.PdfFileReader(pdffileobj)
            num_pages = pdfreader.numPages

            for page_num in range(num_pages):
                pageobj = pdfreader.getPage(page_num)
                text = pageobj.extractText()

                txt_out.write(f"\n\n===== {filename} - página {page_num + 1} =====\n")
                txt_out.write(text)