import os
import PyPDF2

base_dir = r"C:\Users\nunos\EI-ipb-Pasta_Partilhada\2_Ano\1_Semestre\BD\pp"

pdf_files = [
    "1_BD_introducao.pdf",
    "2_BD_SGBD.pdf",
    "3_BD_ModeloRelacional.pdf",
    "4_1_BD_Agebra_en.pdf",
    "5_mongoDB_PT",
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