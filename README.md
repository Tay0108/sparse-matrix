# Sparse Matrix

PL:

W tzw. "macierzy rzadkiej" rezygnuje się z rezerwowania pamięci dla każdego elementu macierzy. Pamięta się tylko wartości elementów niezerowych wraz z "współrzędnymi" - numerami wiersza i kolumny (najlepiej wszystko w jednej strukturze).

Proszę napisać program, który zmienia sposób pamiętania macierzy (przepisuje macierz gęstą tworząc rzadką.

Struktura programu:
  - Macierz o elementach typu double w postaci gęstej jest zdefiniowana (i inicjowana przykładowymi danymi) w segmencie głównym.
  - W wersji A (najprostszej) można założyć, że maksymalna liczba elementów różnych od zera jest zadana MAX.
  - W wersji B liczba elementów różnych od zera jest obliczana w funkcji - dodatkowe punkty można uzyskać jeżeli funkcja będzie uniwersalna, tj. będzie poprawnie działać dla różnych rozmiarów macierzy.
  - W wersji C liczba elementów nie jest obliczana, a struktury opisujące kolejne elementy różne od zera będą dodawane "na bieżąco", np. jako kolejne węzły listy.
  - W segmencie głównym jest pętla (pętle), w której jest wywoływana funkcja dodająca do macierzy rzadkiej kolejny element
  - Kolejna funkcja wyprowadza na ekran kolejne elementy niezerowe na podstawie zapisu rzadkiego (wartość i dwie współrzędne).
  - Program można uzupełnić o funkcję, która korzysta z zapisu rzadkiego i znajduje element o wartości największej i najmniejszej oraz przekazuje je do segmentu głównego (w segmencie głównym są one wyprowadzane na ekran).
  - Inne funkcje pomocnicze nie są wykluczone.
  
 Nie korzystamy ze zmiennych globalnych ani z tablic VLA.
