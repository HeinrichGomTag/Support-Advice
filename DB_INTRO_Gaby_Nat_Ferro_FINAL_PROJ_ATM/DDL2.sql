DROP DATABASE IF EXISTS ferro_bank;
CREATE DATABASE IF NOT EXISTS ferro_bank;
USE ferro_bank;

-- crear tabla de atm con el id, name, adress, bankname
CREATE TABLE ATM(
atm_id integer,
atm_name varchar(50),
atm_adress varchar(50),
atm_bankname varchar(50),
primary key (atm_id)
);

-- crear tabla de la tarjeta de credito, numero, nombre del banco, pin, fecha de expedición, saldo, tipo de tarjeta
CREATE TABLE card(
card_num integer,
card_bankname varchar(50),
card_cvv integer,
card_expiry integer,
card_balance integer,
card_type varchar(50),
primary key (card_num)
);

-- crear tabla account, tipo de cuenta, numero de cuenta
CREATE TABLE account(
ac_type varchar(50),
ac_number integer,
primary key (ac_number)
);

-- crear taba de cliente nombre, cliente, telefono
CREATE TABLE customer(
customer_name varchar(50),
customer_id integer,
phone integer,
customer_adress varchar (50),
ac_number integer,
primary key (customer_id),
foreign key (ac_number) references account (ac_number)
);

-- crear tabla del balance actual
CREATE TABLE currents(
current_cant varchar(50)
);

-- crear tabla de ahorros
CREATE TABLE savings(
sav_cant varchar(50)
);

-- crear tabla transacción, nombre, id, status, tipo de transacción
CREATE TABLE transaction(
trans_name varchar(50),
trans_id integer,
trans_status varchar(50),
trans_type varchar(50),
card_num integer,
primary key (trans_id),
foreign key (card_num) REFERENCES card (card_num)
);

-- crear tabla deposito, nombre, id, status, tipo de transacción
CREATE TABLE deposit(
card_num_dest varchar(50),
deposit_id integer,
trans_id integer,
deposit_quantity integer,
primary key (deposit_id),
foreign key (trans_id) references TRANSACTION (trans_id)
);

-- crear tabla sacar dinero, nombre, id, status, tipo de transacción
CREATE TABLE withdraw(
with_id integer,
trans_id integer,
with_quantity integer,
primary key (with_id),
foreign key (trans_id) references TRANSACTION (trans_id)
);
