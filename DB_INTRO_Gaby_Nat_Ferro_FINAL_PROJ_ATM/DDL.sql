DROP DATABASE IF EXISTS ferro_bank;
CREATE DATABASE IF NOT EXISTS ferro_bank;
USE ferro_bank;


-- crear tabla de la tarjeta de credito, numero, nombre del banco, pin, fecha de expedición, saldo, tipo de tarjeta
CREATE TABLE card(
card_num integer(10),
card_balance integer,
primary key (card_num)
);

-- crear tabla account, tipo de cuenta, numero de cuenta
CREATE TABLE account(
ac_type varchar(50),
card_num integer(10),
primary key (card_num),
foreign key (card_num) references card(card_num)
);

-- crear taba de cliente nombre, cliente, telefono
CREATE TABLE customer(
customer_name varchar(50),
card_num integer(10),
primary key (customer_name),
foreign key (card_num) references account (card_num)
);

-- crear tabla transacción, nombre, id, status, tipo de transacción
CREATE TABLE transaction(
origin_card_num integer(10),
destiny_card_num integer(10),
amount decimal,
foreign key (origin_card_num) REFERENCES card (card_num),
foreign key (destiny_card_num) REFERENCES card (card_num)
);
