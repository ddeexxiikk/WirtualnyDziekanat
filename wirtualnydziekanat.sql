SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;


CREATE TABLE `dane_studentow` (
  `LOGIN` text COLLATE utf8_polish_ci NOT NULL,
  `Imię` text COLLATE utf8_polish_ci NOT NULL,
  `Nazwisko` text COLLATE utf8_polish_ci NOT NULL,
  `Kierunek` text COLLATE utf8_polish_ci NOT NULL,
  `Grupa` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

INSERT INTO `dane_studentow` (`LOGIN`, `Imię`, `Nazwisko`, `Kierunek`, `Grupa`) VALUES
('200001', 'Marcin', 'Dubiel', 'IWIK', 11),
('200002', 'Karol', 'Wiśniewski', 'IWIK', 12),
('200003', 'Dominik', 'Zabawa', 'IWIK', 12),
('200004', 'Monika', 'Łękotka', 'IWIK', 11),
('200005', 'Dominika', 'Skocz', 'ET', 12),
('200006', 'Jadwiga', 'Przybyło', 'ET', 11),
('200007', 'Jacek', 'Szeran', 'ET', 11),
('200008', 'Kacper', 'Bluszcz', 'ET', 11),
('200009', 'Mikołaj', 'Wyzięk', 'ET', 12),
('200010', 'Kacper', 'Zabagło', 'IM', 12),
('200011', 'Angelika', 'Przybyło', 'IM', 11),
('200012', 'Jacek', 'Bluszcz', 'IM', 11),
('200013', 'Mikołaj', 'Wydźwięk', 'IM', 12),
('200014', 'Anatolij', 'Zitchenko', 'IM', 12),
('200015', 'Kamil', 'Chrupka', 'IM', 11),
('200016', 'Zuzanna', 'Chrupka', 'IE', 11),
('200017', 'Kamila', 'Przybyło', 'IE', 12),
('200018', 'Jacek', 'Bluszcz', 'IE', 11),
('200019', 'Yaroslaw', 'Chemik', 'IE', 11),
('200020', 'Marcelina', 'Wydźwięk', 'IE', 12),
('200021', 'Grzegorz', 'Chrust', 'IE', 11),
('200022', 'Jarosław', 'Kaczka', 'IE', 12),
('200023', 'Michał', 'Człek', 'IE', 12),
('200024', 'Kamil', 'Kras', 'MS', 12),
('200025', 'Angelina', 'Julie', 'MS', 12),
('200026', 'Kacper', 'Balast', 'MS', 11),
('200027', 'Yuri', 'Klewik', 'MS', 12),
('200028', 'Julian', 'Roślina', 'MS', 12),
('200029', 'Jan', 'Komik', 'MS', 11),
('200030', 'Gregorij', 'Anataczko', 'MS', 11),
('200031', 'Julienne', 'Assange', 'MS', 11),
('200032', 'Julia', 'Kram', 'IT', 11),
('200033', 'Kacper', 'Chlew', 'IT', 11),
('200034', 'Michał', 'Wiśniewski', 'IT', 12),
('200035', 'Karol', 'Klimko', 'IT', 11),
('200036', 'Józef', 'Zawadzki', 'IT', 12),
('200037', 'Małgorzata', 'Wybitna', 'IT', 12);

CREATE TABLE `ksiażki_studentów` (
  `LOGIN` text COLLATE utf8_polish_ci NOT NULL,
  `Książka` text COLLATE utf8_polish_ci NOT NULL,
  `Data_Wypożyczenia` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

INSERT INTO `ksiażki_studentów` (`LOGIN`, `Książka`, `Data_Wypożyczenia`) VALUES
('200001', 'Pan Tadeusz 2', '2022-10-11'),
('200002', 'Firewall, który nie powstrzyma prawdziwego smoka 2', '2022-10-09'),
('200004', 'Jak zrozumieć system UNIX dla niewtajemniczonych 7', '2022-10-09'),
('200005', 'Podstawy C++ dla studentów informatyki 10', '2022-10-07'),
('200007', 'Pan Tadeusz 2', '2022-10-06'),
('200009', 'Pan Wołodyjowski 10', '2022-10-10'),
('200010', 'Pan Wołodyjowski 3', '2022-10-10'),
('200011', 'Wiedźmin 7', '2022-10-14'),
('200015', 'Wiedźmin 3', '2022-10-17'),
('200016', 'Wiedźmin 11', '2022-10-20'),
('200017', 'Podstawy C++ dla studentów informatyki 20', '2022-10-25'),
('200020', 'Pan Tadeusz 10', '2022-10-03'),
('200003', 'Firewall, który nie powstrzyma prawdziwego smoka 1', '2022-10-10'),
('200005', 'Podstawy C++ dla studentów informatyki 23', '2022-10-09'),
('200006', 'Podstawy C++ dla studentów informatyki 25', '2022-10-07'),
('200008', 'Wiedźmin 1', '2022-10-05'),
('200011', 'Pan Wołodyjowski 12', '2022-10-11'),
('200012', 'Pan Wołodyjowski 4', '2022-10-11'),
('200013', 'Pan Tadeusz 13', '2022-10-13'),
('200014', 'Pan Tadeusz 14', '2022-10-17'),
('200018', 'Pan Tadeusz 15', '2022-10-20'),
('200025', 'Firewall, który nie powstrzyma prawdziwego smoka 8', '2022-10-24'),
('200030', 'Jak zrozumieć system UNIX dla niewtajemniczonych 20', '2022-10-03'),
('200030', 'Podstawy C++ dla studentów informatyki 15', '2022-10-10');

CREATE TABLE `oceny_studentow` (
  `LOGIN` text COLLATE utf8_polish_ci NOT NULL,
  `Ocena` int(11) NOT NULL,
  `Przedmiot` text COLLATE utf8_polish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

INSERT INTO `oceny_studentow` (`LOGIN`, `Ocena`, `Przedmiot`) VALUES
('200010', 4, 'Materiałoznastwo'),
('200015', 3, 'Inżynieria Materiałów'),
('200002', 5, 'Programowanie w języku C++'),
('200001', 2, 'Programowanie w języku Python'),
('200009', 5, 'Procesy łączenia'),
('200006', 5, 'Fizyka'),
('200016', 2, 'Prądoznastwo'),
('200020', 2, 'Programowanie w języku C'),
('200033', 2, 'Algorytmika'),
('200035', 2, 'Programowanie w języku C/C++'),
('200029', 2, 'Algebra'),
('200027', 2, 'Matematyka Stosowana');

CREATE TABLE `plany_zajec` (
  `Kierunek` text COLLATE utf8_polish_ci NOT NULL,
  `Grupa` int(11) NOT NULL,
  `Tygodniowy Plan Zajęć:` text COLLATE utf8_polish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

INSERT INTO `plany_zajec` (`Kierunek`, `Grupa`, `Tygodniowy Plan Zajęć:`) VALUES
('IWIK', 11, 'Poniedziałek: 5 wykładów\r\nWtorek: 2 wykłady\r\nŚroda: 6 wykładów\r\nCzwartek: 3 wykłady\r\nPiątek: 5 wykładów'),
('IWIK', 12, 'Poniedziałek: 4 wykładów\r\nWtorek: 3 wykłady\r\nŚroda: 7 wykładów\r\nCzwartek: 5 wykłady\r\nPiątek: 4 wykładów'),
('ET', 11, 'Poniedziałek: 4 wykładów\r\nWtorek: 2 wykłady\r\nŚroda: 5 wykładów\r\nCzwartek: 3 wykłady\r\nPiątek: 3 wykładów'),
('ET', 12, 'Poniedziałek: 5 wykładów\r\nWtorek: WOLNE\r\nŚroda: 5 wykładów\r\nCzwartek: 4 wykłady\r\nPiątek: 3 wykładów'),
('IM', 11, 'Poniedziałek: 5 wykładów\r\nWtorek: 4 wykłady\r\nŚroda: 3 wykładów\r\nCzwartek: 3 wykłady\r\nPiątek: WOLNE'),
('IM', 12, 'Poniedziałek: 4 wykładów\r\nWtorek: 3 wykłady\r\nŚroda: 4 wykładów\r\nCzwartek: 4 wykłady\r\nPiątek: WOLNE'),
('IE', 11, 'Poniedziałek: 5 wykładów\r\nWtorek: 6 wykłady\r\nŚroda: 4 wykładów\r\nCzwartek: WOLNE\r\nPiątek: WOLNE'),
('IE', 12, 'Poniedziałek: 5 wykładów\r\nWtorek: 5 wykłady\r\nŚroda: 5 wykładów\r\nCzwartek: WOLNE\r\nPiątek: WOLNE'),
('MS', 11, 'Poniedziałek: WOLNE\r\nWtorek: 3 wykłady\r\nŚroda: 3 wykładów\r\nCzwartek: 5 wykłady\r\nPiątek: 5 wykładów'),
('MS', 12, 'Poniedziałek: WOLNE\r\nWtorek: 4 wykłady\r\nŚroda: 4 wykładów\r\nCzwartek: 4 wykłady\r\nPiątek: 4 wykładów'),
('IT', 11, 'Poniedziałek: WOLNE\r\nWtorek: 6 wykłady\r\nŚroda: 6 wykładów\r\nCzwartek: 6 wykłady\r\nPiątek: WOLNE'),
('IT', 12, 'Poniedziałek: WOLNE\r\nWtorek: 7 wykłady\r\nŚroda: 6 wykładów\r\nCzwartek: 5 wykłady\r\nPiątek: WOLNE');

CREATE TABLE `users` (
  `LOGIN` text COLLATE utf8_polish_ci NOT NULL,
  `Password` text COLLATE utf8_polish_ci NOT NULL,
  `Poziom_Dostepu` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

INSERT INTO `users` (`LOGIN`, `Password`, `Poziom_Dostepu`) VALUES
('100001', '1PassWORD_0', 2),
('100002', '2PassWORD_1', 2),
('100003', '3PassWORD_2', 2),
('100004', '4PassWORD_3', 2),
('100005', '5PassWORD_4', 2),
('100006', '6PassWORD_5', 2),
('100007', '7PassWORD_6', 2),
('100008', '8PassWORD_7', 2),
('100009', '9PassWORD_8', 2),
('100010', '9PassWORD_9', 2),
('200001', '1PassWORD_0', 1),
('200002', '2PassWORD_1', 1),
('200003', '3PassWORD_2', 1),
('200004', '4PassWORD_3', 1),
('200005', '5PassWORD_4', 1),
('200006', '6PassWORD_5', 1),
('200007', '7PassWORD_6', 1),
('200008', '8PassWORD_7', 1),
('200009', '9PassWORD_8', 1),
('200010', '10PassWORD_9', 1),
('200011', '11PassWORD_10', 1),
('200012', '12PassWORD_11', 1),
('200013', '13PassWORD_12', 1),
('200014', '14PassWORD_13', 1),
('200015', '15PassWORD_14', 1),
('200016', '16PassWORD_15', 1),
('200017', '17PassWORD_16', 1),
('200018', '18PassWORD_17', 1),
('200019', '19PassWORD_18', 1),
('200020', '20PassWORD_19', 1),
('200021', '21PassWORD_20', 1),
('200022', '22PassWORD_21', 1),
('200023', '23PassWORD_22', 1),
('200024', '24PassWORD_23', 1),
('200025', '25PassWORD_24', 1),
('200026', '26PassWORD_25', 1),
('200027', '27PassWORD_26', 1),
('200028', '28PassWORD_27', 1),
('200029', '29PassWORD_28', 1),
('200030', '30PassWORD_29', 1),
('200031', '31PassWORD_30', 1),
('200032', '32PassWORD_31', 1),
('200033', '33PassWORD_32', 1),
('200034', '34PassWORD_33', 1),
('200035', '35PassWORD_34', 1),
('200036', '36PassWORD_35', 1),
('200037', '37PassWORD_36', 1);


ALTER TABLE `dane_studentow`
  ADD PRIMARY KEY (`LOGIN`(100));

ALTER TABLE `users`
  ADD PRIMARY KEY (`LOGIN`(100));
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
