use test;

create table Now_magazine_subscription
(no smallint primary key, 
CN_no char(10),
ISSN_no char(10),
Post_issue_no char(10),
Image_name char(20),
Public_time char(10),
Public_place char(10),
Organizer char(15),
Subscribe_num smallint
)character set = utf8;

create table Past_magazine_subscription
(CN_no char(10),
ISSN_no char(10),
Post_issue_no char(10)primary key,
Image_name char(20),
Public_time char(10),
Public_place char(10),
Organizer char(15),
Subscribe_num smallint,
Time_tag char(10)
)character set = utf8;

create table Book
(
no smallint Primary Key,
cnNo char(10),
name char(20),
nian char(6),
juan char(6),
qi char(6),
num smallint,
aviNum smallint
)character set = utf8;

create table content
(Article_logo float primary key,
 name char(20),
 author char(40),
 kwd char(40),
 InImage_name char(20),
 InCN_no char(10),
 nian char(6),
 juan char(6),
 qi char(6),
 Startpage_no smallint,
 Endpage_no smallint)character set = utf8;
 
create table borrowList
(
cnNo char(10),
nian char(6),
juan char(6),
qi char(6),
stuNo char(10),
borrowDate char(20),
borrowDays smallint,
returnDate char(20),
actulRetDaye char(20),
primary key(cnNo, nian, juan, qi, stuNo)
)character set = utf8;

create table Next_magazine_subscription
(Post_issue_no char(10)primary key,
Image_name char(20),
Subscribe_num smallint,
Subscribe_time char(20)
)character set = utf8;

create table userList
(
no smallint Primary Key,
stuNo char(10),
name char(10),
grade char(10),
graduate char(20)
)character set = utf8;

