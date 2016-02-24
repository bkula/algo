# Witaj w repozytorium algo

[Algo](https://github.com/bkula/algo) ma zapewnić łatwy dostęp do implementacji najpopulaniejszych problemów algorytmicznych. Rozwiązania powinny być czytelne, zoptymalizowane czasowo i pamięciowo oraz elastyczne (tak by dało się je łatwo przerobić i wykorzystać w rozwiązywaniu innego problemu).

#### Strony z których czerpię pomysły

- [Kurs podstaw algorytmiki - main2](http://main2.edu.pl/main2/courses/show/7/)
- [Algorytmy i struktury danych - materiały I LO w Tarnowie](http://eduinf.waw.pl/inf/alg/001_search/index.php)
- [Algorytmika praktyczna w konkursach informatycznych - praca magisterska](http://www-users.mat.umk.pl/~stencel/acm/algorytmika_praktyczna.pdf)

#### Coding style

- `iostream` + `ios_base::sync_with_stdio(0)` zamiast `cstdio`
- unikam zmiennych globalnych ale nie są on zabronione
- pakuj ile się do do `main`-a
- jak najczęsciej pakuj zmienne w `struct`-a
- używaj raczej wskaźników niż id-ków
- jeśli STL coś zaimplementował, nie implementuj tego poraz drugi
