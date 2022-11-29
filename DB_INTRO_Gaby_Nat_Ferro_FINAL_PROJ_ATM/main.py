opc = -1

import random

import mysql.connector

database = mysql.connector.connect(
    host="localhost",
    user="root",
    password="",
    database="ferro_bank"
)
cursor = database.cursor()

while opc != 0:
    print()
    print("MAIN MENU")
    print("1 - Create Account")
    print("2 - Deposit")
    print("3 - Withdraw")
    print("4 - Transfer")
    print("5 - Check Balance")
    print("0 - EXIT")

    opc = int(input("Choose an option: "))

    if opc == 1:
        print("ADD CUSTOMER")
        name = input("Name: ")
        number = ""
        for x in range(0, 9):
            number += str(random.randint(0, 9))
        int(number)
        print("Your card number: " + number)

        sql = "INSERT INTO customer (customer_name, card_num) VALUES (%s, %s)"
        val = (name, number)
        cursor.execute(sql, val)

        database.commit()
        print("Customer added successfully!")

        sql = "INSERT INTO account (ac_type, card_num) VALUES (%s, %s)"
        val = ("Current", number)
        cursor.execute(sql, val)

        database.commit()
        print("Account added successfully!")

        sql = "INSERT INTO card (card_num, card_balance) VALUES (%s, %s)"
        val = (number, 0)
        cursor.execute(sql, val)

        database.commit()
        print("Card added successfully!")

    elif opc == 2:
        print("DEPOSIT")
        number = input("Card number: ")
        amount = int(input("Amount: "))

        sql = "UPDATE card SET card_balance = card_balance + %s WHERE card_num = %s"
        val = (amount, number)
        cursor.execute(sql, val)

        database.commit()
        print("Deposit successfully!")

    elif opc == 3:
        print("WITHDRAW")
        number = input("Card number: ")
        amount = int(input("Amount: "))

        sql = "UPDATE card SET card_balance = card_balance - %s WHERE card_num = %s"
        val = (amount, number)
        cursor.execute(sql, val)

        database.commit()
        print("Withdraw successfully!")

    elif opc == 4:
        print("TRANSFER")
        origin = input("Origin card number: ")
        destiny = input("Destiny card number: ")
        amount = float(input("Amount: "))

        sql = "UPDATE card SET card_balance = card_balance - %s WHERE card_num = %s"
        val = (amount, origin)
        cursor.execute(sql, val)

        sql = "UPDATE card SET card_balance = card_balance + %s WHERE card_num = %s"
        val = (amount, destiny)
        cursor.execute(sql, val)

        database.commit()
        print("Transfer successfully!")

    elif opc == 5:
        print("CHECK BALANCE")
        number = input("Card number: ")

        sql = "SELECT card_balance FROM card WHERE card_num = %s"
        val = (number,)
        cursor.execute(sql, val)

        result = cursor.fetchone()
        print("Balance: " + str(result[0]))

    elif opc == 0:
        print("Finishing...")
    else:
        print("Opción inválida")
