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

-- insertar atm
INSERT INTO ATM (atm_id, atm_name, atm_adress, atm_bankname) VALUES (75840509, 'Santander', 'Universidad Panamericana', 'Santander');
INSERT INTO ATM (atm_id, atm_name, atm_adress, atm_bankname) VALUES (47911459, 'Santander', 'Universidad Panamericana', 'Santander');
INSERT INTO ATM (atm_id, atm_name, atm_adress, atm_bankname) VALUES (46793770, 'Santander', 'Universidad Panamericana', 'Santander');
INSERT INTO ATM (atm_id, atm_name, atm_adress, atm_bankname) VALUES (60525083, 'Santander', 'Universidad Panamericana', 'Santander');
INSERT INTO ATM (atm_id, atm_name, atm_adress, atm_bankname) VALUES (79122169, 'Santander', 'Universidad Panamericana', 'Santander');
INSERT INTO ATM (atm_id, atm_name, atm_adress, atm_bankname) VALUES (18909178, 'Santander', 'Universidad Panamericana', 'Santander');
INSERT INTO ATM (atm_id, atm_name, atm_adress, atm_bankname) VALUES (36897395, 'Santander', 'Universidad Panamericana', 'Santander');
INSERT INTO ATM (atm_id, atm_name, atm_adress, atm_bankname) VALUES (41039921, 'Santander', 'Universidad Panamericana', 'Santander');
INSERT INTO ATM (atm_id, atm_name, atm_adress, atm_bankname) VALUES (32801548, 'Santander', 'Universidad Panamericana', 'Santander');
INSERT INTO ATM (atm_id, atm_name, atm_adress, atm_bankname) VALUES (58264146, 'Santander', 'Universidad Panamericana', 'Santander');


-- insertar tarejta
INSERT INTO card (card_num, card_bankname, card_cvv, card_expiry, card_balance, card_type) VALUES (3479526441677780, 'Santander', 5993 , 2/2024, 471207370, 'Debito');
INSERT INTO card (card_num, card_bankname, card_cvv, card_expiry, card_balance, card_type) VALUES (2619146024049190, 'Santander', 4026 , 9/2027, 958083, 'Debito');
INSERT INTO card (card_num, card_bankname, card_cvv, card_expiry, card_balance, card_type) VALUES (2455061567488860, 'Santander', 2200 , 7/2028, 691937400, 'Debito');
INSERT INTO card (card_num, card_bankname, card_cvv, card_expiry, card_balance, card_type) VALUES (4329103062901580, 'Santander', 6891 , 6/2030, 703810, 'Debito');
INSERT INTO card (card_num, card_bankname, card_cvv, card_expiry, card_balance, card_type) VALUES (1140752758653300, 'Santander', 8806 , 4/2025, 1978495, 'Debito');
INSERT INTO card (card_num, card_bankname, card_cvv, card_expiry, card_balance, card_type) VALUES (5840319603779570, 'Santander', 2038 , 3/2030, 622092900, 'Debito');
INSERT INTO card (card_num, card_bankname, card_cvv, card_expiry, card_balance, card_type) VALUES (7254242747260610, 'Santander', 6102 , 7/2026, 5125282, 'Debito');
INSERT INTO card (card_num, card_bankname, card_cvv, card_expiry, card_balance, card_type) VALUES (6483098031954040, 'Santander', 3041 , 8/2023, 606618709, 'Debito');
INSERT INTO card (card_num, card_bankname, card_cvv, card_expiry, card_balance, card_type) VALUES (8818031564784380, 'Santander', 6191 , 9/2028, 368775987, 'Debito');
INSERT INTO card (card_num, card_bankname, card_cvv, card_expiry, card_balance, card_type) VALUES (4582626117349680, 'Santander', 7024 , 2/2029, 59645910083, 'Debito');

-- insertar Cliente
INSERT INTO customer (customer_name, customer_id, phone, customer_adress) VALUES ('Serratos Salazar', 555017, 525558071914, 'Gregorio Mendez Magana 6, Estado de México');
INSERT INTO customer (customer_name, customer_id, phone, customer_adress) VALUES ('Mateo Piña', 848758, 525557071914, 'Circuito Interior 229, Benito Juarez, Estado De México');
INSERT INTO customer (customer_name, customer_id, phone, customer_adress) VALUES ('Claudia Vargas', 772154, 525558023423, ' Av Universidad 1000, Benito Juarez, Ciudad de México');
INSERT INTO customer (customer_name, customer_id, phone, customer_adress) VALUES ('Roberto Muñoz', 882994, 525567371914, ' Av Insurgentes Sur 1384,  Benito Juarez, Ciudad de México');
INSERT INTO customer (customer_name, customer_id, phone, customer_adress) VALUES ('Verónica Ruíz', 595477, 525558090915, 'Av Mixcoac 456, Benito Juarez,Ciudad de México');
INSERT INTO customer (customer_name, customer_id, phone, customer_adress) VALUES ('Lorena Torres', 382631, 525558073424, 'Valle de Aragon, Ecatepec de Morelos, Estado de México');
INSERT INTO customer (customer_name, customer_id, phone, customer_adress) VALUES ('José Francisco Ruíz', 520306, 525589071914, 'Villa de Las Flores, San Francisco Coacalco, Estado de México');
INSERT INTO customer (customer_name, customer_id, phone, customer_adress) VALUES ('Ana María Soto', 191577, 525558005614, 'Av Central 735, Nezahualcoyotl, Estado de México');
INSERT INTO customer (customer_name, customer_id, phone, customer_adress) VALUES ('Francisco Vásquez', 556757, 525558071346, 'Gregorio Martinez 67, Estado de México');
INSERT INTO customer (customer_name, customer_id, phone, customer_adress) VALUES ('Lorena Fernández', 677089, 525558077914, 'Valle de los Cerros 46, Estado de México');

-- insertar Cuenta
INSERT INTO account (ac_type, ac_number) VALUES (78905);
INSERT INTO account (ac_type, ac_number) VALUES (46783);
INSERT INTO account (ac_type, ac_number) VALUES (78345);
INSERT INTO account (ac_type, ac_number) VALUES (22783);
INSERT INTO account (ac_type, ac_number) VALUES (78065);
INSERT INTO account (ac_type, ac_number) VALUES (90783);
INSERT INTO account (ac_type, ac_number) VALUES (78678);
INSERT INTO account (ac_type, ac_number) VALUES (34583);
INSERT INTO account (ac_type, ac_number) VALUES (78789);
INSERT INTO account (ac_type, ac_number) VALUES (46090);

-- insertar balance actual
INSERT INTO current (current_cant) VALUES ();
INSERT INTO current (current_cant) VALUES ();
INSERT INTO current (current_cant) VALUES ();
INSERT INTO current (current_cant) VALUES ();
INSERT INTO current (current_cant) VALUES ();
INSERT INTO current (current_cant) VALUES ();
INSERT INTO current (current_cant) VALUES ();
INSERT INTO current (current_cant) VALUES ();
INSERT INTO current (current_cant) VALUES ();
INSERT INTO current (current_cant) VALUES ();

-- insertar ahorros
INSERT INTO savings (sav_cant) VALUES ();
INSERT INTO savings (sav_cant) VALUES ();
INSERT INTO savings (sav_cant) VALUES ();
INSERT INTO savings (sav_cant) VALUES ();
INSERT INTO savings (sav_cant) VALUES ();
INSERT INTO savings (sav_cant) VALUES ();
INSERT INTO savings (sav_cant) VALUES ();
INSERT INTO savings (sav_cant) VALUES ();
INSERT INTO savings (sav_cant) VALUES ();
INSERT INTO savings (sav_cant) VALUES ();

-- insertar transacción
INSERT INTO transaction (trans_name, trans_id,trans_status, trans_type) VALUES ('asunto',63923,'aprobado','SPEI');
INSERT INTO transaction (trans_name, trans_id,trans_status, trans_type) VALUES ('asunto',42711,'aprobado','TEF');
INSERT INTO transaction (trans_name, trans_id,trans_status, trans_type) VALUES ('asunto',37292,'denegada','TEF');
INSERT INTO transaction (trans_name, trans_id,trans_status, trans_type) VALUES ('asunto',36382,'en proceso','SPEI');
INSERT INTO transaction (trans_name, trans_id,trans_status, trans_type) VALUES ('asunto',62840,'aprobado','TEF');
INSERT INTO transaction (trans_name, trans_id,trans_status, trans_type) VALUES ('asunto',37291,'en proceso','SPEI');
INSERT INTO transaction (trans_name, trans_id,trans_status, trans_type) VALUES ('asunto',67183,'denegada','TEF');
INSERT INTO transaction (trans_name, trans_id,trans_status, trans_type) VALUES ('asunto',37611,'aprobado','SPEI');
INSERT INTO transaction (trans_name, trans_id,trans_status, trans_type) VALUES ('asunto',01931,' en proceso','SPEI');
INSERT INTO transaction (trans_name, trans_id,trans_status, trans_type) VALUES ('asunto',62810,'denegada','TEF');

-- insertar deposito
INSERT INTO deposit (card_num_dest, deposit_id, deposit_quantity)VALUES (83023);
INSERT INTO deposit (card_num_dest, deposit_id, deposit_quantity)VALUES (47231);
INSERT INTO deposit (card_num_dest, deposit_id, deposit_quantity)VALUES (47103);
INSERT INTO deposit (card_num_dest, deposit_id, deposit_quantity)VALUES (98183);
INSERT INTO deposit (card_num_dest, deposit_id, deposit_quantity)VALUES (68291);
INSERT INTO deposit (card_num_dest, deposit_id, deposit_quantity)VALUES (98313);
INSERT INTO deposit (card_num_dest, deposit_id, deposit_quantity)VALUES (46102);
INSERT INTO deposit (card_num_dest, deposit_id, deposit_quantity)VALUES (47102);
INSERT INTO deposit (card_num_dest, deposit_id, deposit_quantity)VALUES (09381);
INSERT INTO deposit (card_num_dest, deposit_id, deposit_quantity)VALUES (89102);


-- insertar sacar dinero
INSERT INTO withdraw (with_id,with_quantity) VALUES  (73022);
INSERT INTO withdraw (with_id, with_quantity) VALUES (38102);
INSERT INTO withdraw (with_id, with_quantity) VALUES (72610);
INSERT INTO withdraw (with_id, with_quantity) VALUES (03818);
INSERT INTO withdraw (with_id, with_quantity) VALUES (47201);
INSERT INTO withdraw (with_id, with_quantity) VALUES (84720);
INSERT INTO withdraw (with_id, with_quantity) VALUES (09381);
INSERT INTO withdraw (with_id, with_quantity) VALUES (40019);
INSERT INTO withdraw (with_id, with_quantity) VALUES (03910);
INSERT INTO withdraw (with_id, with_quantity) VALUES (09381);


