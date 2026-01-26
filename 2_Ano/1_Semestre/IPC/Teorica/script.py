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
            # usar a nova API do PyPDF2 (v3+)
            pdfreader = PyPDF2.PdfReader(pdffileobj)
            num_pages = len(pdfreader.pages)

            for page_num in range(num_pages):
                pageobj = pdfreader.pages[page_num]
                text = pageobj.extract_text() or ""

                txt_out.write(f"\n\n===== {filename} - página {page_num + 1} =====\n")
                txt_out.write(text)

print("Terminado. Verifica o ficheiro 'arquivo.txt' nesta pasta.")