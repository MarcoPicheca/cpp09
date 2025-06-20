## 🇮🇹 ITALIANO

# 42 C++ Module 09
---
# 🪙 Exercise 00: Bitcoin Exchange 

Ti chiede di scrivere un programma in C++ chiamato btc che calcoli il valore di una certa quantità di bitcoin in una specifica data, basandosi su uno storico dei prezzi contenuto in un file CSV.
per questo esercizio ho utilizzato il **container std::vector**, perchè il subject richiedeva di non ripetere l'utilizzo della stessa STL. usare **std::map** sarebbe stato meglio e più semplice ma mi piace sfidarmi!

## 📌 Obiettivo
- Il programma deve leggere un file di input fornito da linea di comando, in cui ogni riga rappresenta una richiesta nel formato: YYYY-MM-DD | value
- l programma cerca nel file database CSV allegato (contenente i prezzi storici del bitcoin) il tasso di cambio per quella data. Se la data esatta non esiste, si usa la data precedente più vicina (non quella successiva!).
- Il risultato viene stampato come: es. 2011-01-03 => 2 = 0.6

## ⚠️ Validazioni richieste
- I valori devono essere: numeri positivi (> 0), non superiori a 1000
- Il programma deve gestire errori con messaggi chiari, come:
    > Error: could not open file.
    > Error: not a positive number.
    > Error: bad input => 2001-42-42
    > Error: too large a number.

# 🔢 Exercise 01: Reverse Polish Notation

Questo esercizio ti chiede di implementare un programma in C++ chiamato RPN (Reverse Polish Notation), capace di valutare espressioni matematiche scritte in notazione polacca inversa. Per questo esercizio ho usato il **container std::stack**.

## 📌 Obiettivo
  - Il programma accetta un solo argomento: una stringa che rappresenta un’espressione matematica in notazione RPN (es. "3 4 + 2 *").
  - Tutti i numeri presenti nell’input saranno interi positivi minori di 10, ma il risultato può superare questi limiti.
  - Il programma valuta l’espressione e stampa il risultato su standard output.
  - In caso di errore (formato sbagliato, divisione per zero, operazione malformata), il programma stampa "Error" su standard error.

## ➕ Operatori supportati
Il programma deve gestire solo i seguenti operatori:
  - "+" ➝ somma
  - "-" ➝ sottrazione
  - "*" ➝ moltiplicazione
  - "/" ➝ divisione intera

# 📈 Exercise 02: PmergeMe

PmergeMe è un esercizio che ti richiede di implementare un programma in C++ in grado di ordinare una sequenza di interi positivi tramite l’algoritmo Merge-Insertion Sort, conosciuto anche come Ford-Johnson algorithm.
Per questo esercizio ho utilizzato due STL (come richiesto dal subject): std::deque e std::list in una versione template sempre per esercizio e sfida.

## 📌 Obiettivo
  - Scrivere un programma chiamato PmergeMe
  - Il programma prende una sequenza di interi positivi da linea di comando
  - L’algoritmo di ordinamento da usare è Ford-Johnson (Merge-Insertion Sort)
  - ATTENZIONE: non dimenticare di usare la Jacobsthal sequence per l'Insertion Sort
  - In caso di errore (input non valido, valori negativi, duplicati, ecc.), il programma deve stampare un messaggio d’errore su stderr
  - Il programma deve gestire almeno 3000 numeri senza rallentamenti significativi

## 🖨️ Output richiesto
Il programma deve stampare 4 righe:
  - La sequenza iniziale (non ordinata), preceduta da un testo esplicito
  - La sequenza ordinata
  - Il tempo di esecuzione (ordinamento + gestione dati) con il primo container
  - Il tempo di esecuzione con il secondo container

## 🇬🇧 English

# 42 C++ Module 09

---

# 🪙 Exercise 00: Bitcoin Exchange

This exercise asks you to write a C++ program named `btc` that calculates the value of a certain amount of bitcoin on a specific date, based on historical price data contained in a CSV file.
For this exercise, I used the **`std::vector`** container, because the subject specified not to reuse the same STL. Using **`std::map`** would have been simpler and more efficient, but I like a challenge!

## 📌 Goal

* The program must read an input file passed via command line, where each line represents a request in the format: `YYYY-MM-DD | value`
* The program searches the attached CSV database (containing historical bitcoin prices) for the exchange rate on that date. If the exact date doesn't exist, it uses the closest previous date (not the next one!).
* The result is printed like: `2011-01-03 => 2 = 0.6`

## ⚠️ Required Validations

* Values must be: positive numbers (> 0), not greater than 1000
* The program must handle errors with clear messages, such as:

  > Error: could not open file.
  > Error: not a positive number.
  > Error: bad input => 2001-42-42
  > Error: too large a number.

# 🔢 Exercise 01: Reverse Polish Notation

This exercise asks you to implement a C++ program named `RPN` (Reverse Polish Notation), capable of evaluating mathematical expressions written in reverse Polish notation. For this exercise, I used the **`std::stack`** container.

## 📌 Goal

* The program accepts a single argument: a string representing a mathematical expression in RPN (e.g. "3 4 + 2 \*").
* All numbers in the input will be positive integers less than 10, but the result may exceed this limit.
* The program evaluates the expression and prints the result to standard output.
* In case of an error (bad format, division by zero, malformed operation), the program prints `Error` to standard error.

## ➕ Supported Operators

The program must handle only the following operators:

* `+` ➔ addition
* `-` ➔ subtraction
* `*` ➔ multiplication
* `/` ➔ integer division

# 📈 Exercise 02: PmergeMe

`PmergeMe` is an exercise that requires you to implement a C++ program capable of sorting a sequence of positive integers using the Merge-Insertion Sort algorithm, also known as the Ford-Johnson algorithm.
For this exercise, I used two STL containers (as required by the subject): `std::deque` and `std::list`, implemented via a templated version for practice and challenge.

## 📌 Goal

* Write a program named `PmergeMe`
* The program takes a sequence of positive integers from the command line
* The sorting algorithm to use is Ford-Johnson (Merge-Insertion Sort)
* WARNING: don't forget to use the Jacobsthal sequence for the insertion phase
* If an error occurs (invalid input, negative values, duplicates, etc.), the program must print an error message to stderr
* The program must handle at least 3000 numbers efficiently

## 🗸 Required Output

The program must print 4 lines:

* The initial sequence (unsorted), with an explanatory label
* The sorted sequence
* The execution time (sorting + data handling) with the first container
* The execution time with the second container
