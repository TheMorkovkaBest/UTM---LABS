import csv
import json

books = {}
janri = {}
autors = {}
data_autors = {}

try:
    f = open("books.csv", newline="", encoding="utf-8")
except FileNotFoundError:
    print("Ошибка: файл 'books.csv' не найден.")
except PermissionError:
    print("Ошибка: нет прав доступа к файлу 'books.csv'.")
else:
    try:
        reader = csv.reader(f)
        number = 0
        for row in reader:
            if len(row) == 0 or row[0] == 'Name':
                continue

            if len(row) < 4 or not row[0].strip() or not row[1].strip() or not row[2].strip() or not row[3].strip():
                continue
            try:
                year = int(row[2].strip())
            except ValueError:
                continue


            books[number] = " // ".join([row[0], row[1], row[3], row[2]])

            genre = row[3]
            autor = row[1]

            if genre in janri:
                janri[genre].append(number)
            else:
                janri[genre] = [number]

            if autor in autors:
                autors[autor][0] += 1
            else:
                autors[autor] = [1]

            number += 1


        data_autors = dict(sorted(autors.items(), key=lambda au: au[1], reverse=True))
    finally:
        f.close()


def filter(year1, year2):
    data = []
    for i in range(len(books)):
        parts = books[i].split(" // ")
        try:
            y = int(parts[3].strip())
            if year1 <= y <= year2:
                data.append(parts[0] + ' // ' + parts[3].strip())
        except ValueError:
            continue
    try:
        f = open('filter.json', 'w', encoding='utf-8')
        json.dump(data, f, ensure_ascii=False)
    except Exception as e:
        print("Ошибка при записи в filter.json:", e)
    else:
        print("Файл filter.json успешно сохранён.")
    finally:
        f.close()


def autorsloadtofile():
    try:
        z = open("top_authors.csv", "w", newline="", encoding="utf-8")
        w = csv.writer(z)
        w.writerow(["author", "count"])
        for k, v in data_autors.items():
            w.writerow((k, v))
    except Exception as e:
        print("Ошибка при записи в top_authors.csv:", e)
    else:
        print("Файл top_authors.csv успешно сохранён.")
    finally:
        z.close()


autorsloadtofile()
filter(1998, 2004)

try:
    print("\nstatistic:")
    print("общее количество книг:", len(books))
    print("отдельные жанры:", ", ".join(janri.keys()))
    if data_autors:
        print("автор с наибольшим количеством названий:" , next(iter(data_autors)))
    else:
        print("автор с наибольшим количеством названий: нет данных")
except Exception as e:
    print("Ошибка при выводе статистики:", e)
