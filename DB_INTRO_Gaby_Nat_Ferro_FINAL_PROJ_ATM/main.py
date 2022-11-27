# IMPORT MODULES
import mysql.connector

# CREATE DATABASE CONNECTION
database = mysql.connector.connect(
    host="localhost",
    user="root",
    password="",
    database="ferro_bank"
)
# SEE OBJECT ADDRESS
# print(database)

# CREATE CURSOR
cursor = database.cursor()

# VIEW ALL DATABASES
# cursor.execute("SHOW DATABASES")
# for x in cursor:
#     print(x)

# VIEW ALL TABLES FROM SELECTED DATABASE
# cursor.execute("SHOW TABLES")
# for x in cursor:
#     print(x)

# CREATE TABLE
# cursor.execute("CREATE TABLE savings (sav_cant varchar(50))")

# INSERT 1 ROW INTO TABLE "account"
# sql = "INSERT INTO account (ac_type, ac_number) VALUES (%s, %s)"
# val = ("Ahorro", "123456789")
# cursor.execute(sql, val)

# CLEAN TABLE
# cursor.execute("TRUNCATE TABLE account")

# INSERT MULTIPLE ROW INTO TABLE "account"
# sql = "INSERT INTO account (ac_type, ac_number) VALUES (%s, %s)"
# val = [
#     ("Ahorro", "123456789"),
#     ("Corriente", "987654321")
# ]
# cursor.executemany(sql, val)


def insert_account(ac_type, ac_number):
    sql = "INSERT INTO account (ac_type, ac_number) VALUES (%s, %s)"
    val = (ac_type, ac_number)
    cursor.execute(sql, val)


tipo = input("Ingrese el tipo de cuenta: ")
numero = int(input("Ingrese el número de cuenta: "))
insert_account(tipo, numero)

database.commit()

# GET NUMBER OF ROWS
print(cursor.rowcount, "records inserted.")

# GET LAST ROW ID
# print("Last record ID: ", cursor.lastrowid)
