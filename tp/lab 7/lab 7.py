import tkinter as tk
from tkinter import messagebox
import requests
from bs4 import BeautifulSoup
from PIL import Image, ImageTk
from io import BytesIO
from urllib.parse import urljoin

page_number =0
glob_page_number = 1
static_url = ''
save_arr = []

def page_up():
    global page_number
    page_number+=3
    scrape_books()


def  page_down():
    global page_number
    if page_number>=3:
        page_number-=3
        scrape_books()

def saving_book(n, book1, book2, book3):
    global save_arr
    if n == 1:
        save_arr.append(book1)
    if n == 2:
        save_arr.append(book2)
    if n == 3:
        save_arr.append(book3)
    if n == 4:
        save_arr.append(book1)
        save_arr.append(book2)
        save_arr.append(book3)

def saving():
    global save_arr
    with open('saving.txt','w') as f:
        f.write('')
    with open('saving.txt','a') as f:
        for i in save_arr:
            f.write(str(i))
            f.write('\n')

def scrape_books():
    global first_time, field1, field2, field3
    global img1_label, img2_label, img3_label
    global page_number , url , glob_page_number , static_url
    book1, book2, book3 = None,None,None

    try:
        resp = requests.get(url)
        resp.raise_for_status()
    except Exception as e:
        messagebox.showerror("Ошибка", f"Не удалось загрузить страницу:\n{e}")
        return
    url_entry.delete(0, tk.END)
    soup = BeautifulSoup(resp.text, "html.parser")
    books = soup.find_all("article", class_="product_pod")

    if not books:
        messagebox.showinfo("Инфо", "Книги не найдены")
        return

    if first_time:

        field1 = tk.Text(root, width=40, height=15)
        field1.pack(side="left", padx=5, pady=5)
        img1_label = None

        field2 = tk.Text(root, width=40, height=15)
        field2.pack(side="left", padx=5, pady=5)
        img2_label = None

        field3 = tk.Text(root, width=40, height=15)
        field3.pack(side="left", padx=5, pady=5)
        img3_label = None

        tk.Button(root, text="Следующая страница", command=page_up).pack()
        tk.Button(root, text="Предыдущая страница", command=page_down).pack()
        tk.Button(root, text="добавить 1-ую книгу", command=lambda :saving_book(1,book1,book2,book3)).pack()
        tk.Button(root, text="добавить 2-ую книгу", command=lambda :saving_book(2,book1,book2,book3)).pack()
        tk.Button(root, text="добавить 3-ую книгу", command=lambda :saving_book(3,book1,book2,book3)).pack()
        tk.Button(root, text="добавить все книги", command=lambda :saving_book(4,book1,book2,book3)).pack()
        tk.Button(root, text="сохранить", command=saving).pack()
        first_time = False

    field1.delete("1.0", tk.END)
    field2.delete("1.0", tk.END)
    field3.delete("1.0", tk.END)

    if img1_label:
        img1_label.destroy()
    if img2_label:
        img2_label.destroy()
    if img3_label:
        img3_label.destroy()

    for i, book in enumerate(books):
        if i < page_number or i >= page_number + 3:
            continue

        title = book.h3.a["title"]
        price = book.find("p", class_="price_color").text

        img_url = book.find("img")["src"]
        img_url = urljoin(url, img_url)

        img = Image.open(BytesIO(requests.get(img_url).content))
        img = img.resize((120, 150))
        photo = ImageTk.PhotoImage(img)

        if i % 3 == 0:
            field1.insert("end", f"{title}\n{price}\n")
            img1_label = tk.Label(field1, image=photo)
            img1_label.image = photo
            field1.window_create("end", window=img1_label)
            book1 = [title,price,img_url]
        elif i % 3 == 1:
            field2.insert("end", f"{title}\n{price}\n")
            img2_label = tk.Label(field2, image=photo)
            img2_label.image = photo
            field2.window_create("end", window=img2_label)
            book2 = [title, price, img_url]
        elif i % 3 == 2:
            field3.insert("end", f"{title}\n{price}\n")
            img3_label = tk.Label(field3, image=photo)
            img3_label.image = photo
            field3.window_create("end", window=img3_label)
            book3 = [title, price, img_url]


    if field1.get("1.0", "end-1c").strip() == "" :
        glob_page_number += 1
        page_number = -3
        if url.endswith("/"):
            url = urljoin(static_url, "catalogue/page-"+str(glob_page_number)+".html")
        else:
            url = urljoin(static_url + "/","catalogue/page-"+str(glob_page_number)+".html")

        resp = requests.get(url)
        if resp.status_code != 200:
            messagebox.showerror("Ошибка", "Страниц больше нет")
            return

        soup = BeautifulSoup(resp.text, "html.parser")
        books = soup.find_all("article", class_="product_pod")

        if not books:
            messagebox.showinfo("Инфо", "Книги не найдены")
            return
        page_up()



def get_url():
    global url ,static_url
    static_url= url = url_entry.get()
    scrape_books()




root = tk.Tk()
root.title("Парсер книг")
tk.Label(root, text="URL:").pack()
url_entry = tk.Entry(root, width=50)
url_entry.pack()
url_entry.insert(0, "http://books.toscrape.com/")
first_time = True
url = ""
tk.Button(root, text="Читать страницу", command=get_url).pack(pady=0, padx=0)
root.mainloop()

