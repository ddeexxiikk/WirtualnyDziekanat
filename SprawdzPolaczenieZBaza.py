from mysql.connector import connect

plik1 = open("wynik.txt", "w")

try:
    connection = connect(
        host="localhost",
        user="ddeexxiikk",
        password="A*pxqKxM3rTzke7v_.*@",
        database="wirtualnydziekanat"
    )

    if connection != None:
        plik1.write("TRUE")
except Exception as e:
     plik1.write("FALSE")

plik1.close()