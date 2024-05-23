Grafy są istotną strukturą danych używaną w informatyce. Zadanie polega na wczytaniu grafów i wyznaczeniu następujących parametrów:

1. ciągu stopniowego;
2. liczby składowych spójności; 
3. dwudzielności grafu; 
4. acentryczności wierzchołków (w ramach składowych spójności); 
5. planarności grafu; 
6. kolory wierzchołków (kolejne liczby naturalne od 1) uzyskane za pomocą algorytmów:
   - zachłannego w kolejności wierzchołków zgodnej z numerem wierzchołka 
   - metodą LF (remisy rozwiązujemy przy pomocy numeru wierzchołka)
   - metodą SLF (w przypadku remisu wybierz wierzchołek z najwyższym stopniem, a jeśli nadal jest remis to wierzchołek o najmniejszym indeksie) 
7. liczba różnych podgrafów C4
8. liczba krawędzi dopełnienia grafu 

Wejście
W pierwszej linii znajduje się liczba k grafów.
W kolejnych liniach znajduje się k zestawów danych grafów.
Pojedynczy zestaw danych zawiera liczbę n - rząd grafu - oraz listę sąsiadów w postaci liczba sąsiadów (s) wraz z s identyfikatorami sąsiadów.
Identyfikatory sąsiadów to liczby z zakresu od 1 do n.
Wyjście
Należy wypisać k zestawów odpowiedzi.
Każdy zestaw powinien zawierać wyznaczone parametry w kolejności w jakiej parametry są wypisane. W przypadku punktów

- 1, 4, 6a, 6b, 6c należy wypisać ciąg n liczb;
- 7, 8 należy wypisać liczbę;
- 2, 3, 5 należy wypisać T lub F (prawda/fałsz). 

Opcjonalność
W zadaniu jedynie podpunkty 1 i 2 są wymagane. Jeśli jakiś z podpunktów nie będzie realizowany, to w odpowiedzi należy wpisać pojedynczy znak '?'.
Punktacja za parametr grafu zostaną uwzględnione tylko wtedy, jeśli w każdym zestawie danych ten parametr zostanie prawidłowo wyznaczony.
Punktacja za każdy z parametrów to 10% całkowitej punktacji. 