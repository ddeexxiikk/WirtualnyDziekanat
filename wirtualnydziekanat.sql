SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;


CREATE TABLE `dane_studentow` (
  `LOGIN` text COLLATE utf8_polish_ci NOT NULL,
  `Imię` text COLLATE utf8_polish_ci NOT NULL,
  `Nazwisko` text COLLATE utf8_polish_ci NOT NULL,
  `Kierunek` text COLLATE utf8_polish_ci NOT NULL,
  `Plan Zajęć` text COLLATE utf8_polish_ci NOT NULL,
  `Grupa` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

CREATE TABLE `ksiażki_studentów` (
  `L.P` int(11) NOT NULL,
  `LOGIN` text COLLATE utf8_polish_ci NOT NULL,
  `Książka` text COLLATE utf8_polish_ci NOT NULL,
  `Data_Wypożyczenia` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

CREATE TABLE `oceny_studentow` (
  `L.P` int(11) NOT NULL,
  `LOGIN` text COLLATE utf8_polish_ci NOT NULL,
  `Ocena` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

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

ALTER TABLE `ksiażki_studentów`
  ADD PRIMARY KEY (`L.P`);

ALTER TABLE `oceny_studentow`
  ADD PRIMARY KEY (`L.P`);

ALTER TABLE `users`
  ADD PRIMARY KEY (`LOGIN`(100));


ALTER TABLE `ksiażki_studentów`
  MODIFY `L.P` int(11) NOT NULL AUTO_INCREMENT;

ALTER TABLE `oceny_studentow`
  MODIFY `L.P` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
