USE storeco;

CREATE TABLE region(
       region_id INT(3) PRIMARY KEY,
       region_descript VARCHAR(35) NOT NULL,
       UNIQUE (region_id)
);

CREATE TABLE store(
       store_id INT(5) PRIMARY KEY,
       store_name VARCHAR(20) NOT NULL,
       store_ytd_sales NUMERIC(11,2) NOT NULL,
       region_id INT(3) NOT NULL,
       FOREIGN KEY (region_id)
       REFERENCES region(region_id),
       UNIQUE (store_id)
);

CREATE TABLE employee(
       emp_id INT(5) PRIMARY KEY,
       emp_title VARCHAR(20) NOT NULL,
       emp_fname VARCHAR(20) NOT NULL,
       emp_lname VARCHAR(20) NOT NULL,
       emp_initial CHAR(1) NOT NULL,
       emp_dob DATE NOT NULL,
       emp_gender CHAR(1) NOT NULL,
       store_id INT(5) NOT NULL,
       FOREIGN KEY (store_id)
       REFERENCES store(store_id),
       emp_manager CHAR(5) NOT NULL,
       UNIQUE (emp_id)
);

CREATE TABLE vendor(
       vendor_id INT(5) PRIMARY KEY,
       vendor_name VARCHAR(20) NOT NULL,
       vendor_contact VARCHAR(14) NOT NULL,
       vendor_email VARCHAR(30) NOT NULL,
       vendor_areacode CHAR(3) NOT NULL,
       UNIQUE (vendor_id),
       UNIQUE (vendor_contact),
       UNIQUE (vendor_email),
       UNIQUE (vendor_areacode)
);

CREATE TABLE customer(
       cus_id INT(6) PRIMARY KEY,
       cus_lname VARCHAR(30) NOT NULL,
       cus_fname VARCHAR(30) NOT NULL,
       cus_initial CHAR(1) NOT NULL,
       cus_areacode CHAR(3) NOT NULL,
       cus_contact VARCHAR(14) NOT NULL,
       cus_address VARCHAR(30) NOT NULL,
       cus_rank VARCHAR(10) NOT NULL,
       UNIQUE (cus_id),
       UNIQUE (cus_areacode),
       UNIQUE (cus_contact)
);

CREATE TABLE discount(
       dis_id INT(3) PRIMARY KEY,
       dis_condition VARCHAR(30) NOT NULL,
       dis_percent CHAR(3) NOT NULL,
       dis_time DATETIME NOT NULL,
       UNIQUE (dis_id)
);

CREATE TABLE invoice(
       inv_id INT(5) PRIMARY KEY,
       emp_id INT(5) NOT NULL,
       cus_id INT(6) NOT NULL,
       inv_date DATE NOT NULL,
       inv_num CHAR(6) NOT NULL,
       inv_total NUMERIC(8,2) NOT NULL,
       dis_id INT(3) NOT NULL,
       inv_payment_date DATE NOT NULL,
       inv_descript VARCHAR(30) NOT NULL,
       FOREIGN KEY (emp_id)
       REFERENCES employee(emp_id),
       FOREIGN KEY (cus_id)
       REFERENCES customer(cus_id),
       FOREIGN KEY (dis_id)
       REFERENCES discount(dis_id),
       UNIQUE (inv_id)

);

CREATE TABLE product(
       product_id INT(6) PRIMARY KEY,
       product_name VARCHAR(30) NOT NULL,
       product_quantity CHAR(4) NOT NULL,
       product_unit_price NUMERIC(8,2) NOT NULL,
       product_descript VARCHAR(30) NOT NULL,
       manf_date DATE NOT NULL,
       vendor_id INT(5) NOT NULL,
       store_id INT(5) NOT NULL,
       FOREIGN KEY (vendor_id)
       REFERENCES vendor(vendor_id),
       FOREIGN KEY (store_id)
       REFERENCES store(store_id),
       UNIQUE (product_id)
);

CREATE TABLE inv_item(
       inv_id INT(5) PRIMARY KEY,
       product_id INT(6) NOT NULL,
       inv_items_units CHAR(4) NOT NULL,
       inv_items_price NUMERIC(8,2) NOT NULL,
       FOREIGN KEY (inv_id)
       REFERENCES invoice(inv_id),
       FOREIGN KEY (product_id)
       REFERENCES product(product_id)
);