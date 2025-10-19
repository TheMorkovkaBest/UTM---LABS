import csv , json
books = {}
janri = {}
autors = {}
with open("books.csv", newline="", encoding="utf-8") as f:
    reader = csv.reader(f)  # or: csv.DictReader(f)
    number = 0
    for row in reader:
        if str(row[0]) == 'Name': pass
        else:
            books[number] = " // ".join([row[0], row[1], row[3], row[2]])
            genre = row[3]
            autor = row[1]

            if genre in janri:
                janri[genre].append(number)
            else:
                janri[genre] = [number]

            if autor in autors:
                s = 1+autors[autor][0]
                autors[autor].clear()
                autors[autor].append(s)
            else:
                autors[autor] = [1]
            number += 1
        data_autors = dict(sorted(autors.items(), key=lambda  au: au[1], reverse=True))



def filter(year1, year2):
    number = 0
    data = []
    for i in books:
        number += 1
        parts = books[int(number - 1)].split(" // ", 3)
        if year1 <= int(parts[3].strip()) <= year2:
            data.append(parts[0] + ' // ' + parts[3].strip())
    with open('filter.json', 'w', encoding='utf-8') as f:
        json.dump(data, f , ensure_ascii=False )

def autorsloadtofile():
    global autors,data_autors
    with open("top_authors.csv", "w", newline="", encoding="utf-8") as z:
        w = csv.writer(z)
        w.writerow(["author", "count"])
        w.writerows((k, v) for k, v in data_autors.items())




autorsloadtofile()
filter(1998,2004)


print("\nstatistic: \nобщее количество книг:" , len(books))
print("отдельные жанры:", str(janri.keys()).replace("'","").replace("dict_keys([", "").replace("])", ""))
print("автор с наибольшим количеством названий:" , str(next(iter(data_autors))) )