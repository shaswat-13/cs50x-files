-- Keep a log of any SQL queries you execute as you solve the mystery.

-- information i have:
-- theft took place on july 28 on 'Humphrey Street'

-- checking the crime scene reports
SELECT description
FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND street = 'Humphrey Street';

-- theft took place at 10:15 am at the bakery, 3 witnesses whose interview transcripts mentions the bakery

-- checking bakery security logs
SELECT *
FROM bakery_security_logs
WHERE month = 7
AND day = 28
AND hour = 10;

-- on minute 14 > entry > liscense plate no 13FNH73
-- on minute 16 > exit > liscense plate no 5P2BI95

-- checking with month and date for phone number
SELECT *
FROM phone_calls
WHERE month = 7
AND day = 28;

-- a lot of data that gives caller phone no, recievers phone no and duration
-- check out later after deducing more

-- checking for the interview that might mention about theft
SELECT name, transcript
FROM interviews
WHERE month = 7
AND day = 28;

-- ruth > within 10 mins of theft, thief got into car in bakery parking lot and drove away
-- eugene > someone she recognized, earlier in the morning before she got to the bakery, she saw the thief
--          withdrawing money from the ATM on Leggett Street
-- raymond > when the thief was leaving the bakery, they called someone for less than a minute,
--           thief planning on taking earliest flight  out of fiftyville, person on the phone to buy ticket.

-- checking the bakery security logs again
SELECT *
FROM bakery_security_logs
WHERE month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 5 and 25;

-- liscencse plates of cars:
--| 5P2BI95       |16
--| 94KL13X       |18
--| 6P58WS2       |18
--| 4328GD8       |19
--| G412CB7       |20
--| L93JTIZ       |21
--| 322W7JE       |23
--| 0NTHK55       |23

-- checking the atm logs
SELECT *
FROM atm_transactions
WHERE month = 7
AND day = 28
AND atm_location LIKE '%Leggett%'
AND transaction_type LIKE '%withdraw%';

-- got 8 different account numbers and amounts
/*
+----------------+--------+
| account_number | amount |
+----------------+--------+
| 28500762       | 48     |
| 28296815       | 20     |
| 76054385       | 60     |
| 49610011       | 50     |
| 16153065       | 80     |
| 25506511       | 20     |
| 81061156       | 30     |
| 26013199       | 35     |
+----------------+--------+
*/

-- single line comment
/* multiline comment */

-- checking phone calls which lasted less than a minute in that day
SELECT caller, receiver
FROM phone_calls
WHERE month = 7
AND day = 28
AND duration < 60;
/*
+----------------+----------------+
|     caller     |    receiver    |
+----------------+----------------+
| (130) 555-0289 | (996) 555-8899 |
| (499) 555-9472 | (892) 555-8872 |
| (367) 555-5533 | (375) 555-8161 |
| (499) 555-9472 | (717) 555-1342 |
| (286) 555-6063 | (676) 555-6554 |
| (770) 555-1861 | (725) 555-3243 |
| (031) 555-6622 | (910) 555-3251 |
| (826) 555-1652 | (066) 555-9701 |
| (338) 555-6650 | (704) 555-2131 |
+----------------+----------------+
*/

-- from the list of licence plates and phone numbers, narrowing down the person
SELECT *
FROM people
WHERE phone_number IN (

    SELECT caller
    FROM phone_calls
    WHERE month = 7
    AND day = 28
    AND duration < 60
)
AND people.license_plate IN (

    SELECT bakery_security_logs.license_plate
    FROM bakery_security_logs
    WHERE month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 5 and 25
    AND activity LIKE '%exit%'
);

-- four such people found
/*
+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
| 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+--------+----------------+-----------------+---------------+
*/

-- using the above conditions and person id to find the bank account
SELECT *
FROM bank_accounts
WHERE person_id IN (

    SELECT id
    FROM people
    WHERE phone_number IN (

        SELECT caller
        FROM phone_calls
        WHERE month = 7
        AND day = 28
        AND duration < 60
        )
    AND people.license_plate IN (

        SELECT bakery_security_logs.license_plate
        FROM bakery_security_logs
        WHERE month = 7
        AND day = 28
        AND hour = 10
        AND minute BETWEEN 5 and 25
        AND activity LIKE '%exit%'
        )
);

-- only 2 values remain
/*
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 49610011       | 686048    | 2010          | ----> Bruce > withdraw 50
| 26013199       | 514354    | 2012          | ----> Diana > withdraw 35
+----------------+-----------+---------------+
*/

-- finding the airport in fiftyville
SELECT *
FROM airports
WHERE city LIKE '%Fiftyville%';

/*
+----+--------------+-----------------------------+------------+
| id | abbreviation |          full_name          |    city    |
+----+--------------+-----------------------------+------------+
| 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
+----+--------------+-----------------------------+------------+
*/

-- finding out the earliest flight of the next day from the csf airport
SELECT *
FROM flights
WHERE origin_airport_id = 8
AND month = 7
AND day = 29
AND hour < 12
LIMIT 1;

/*
+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
+----+-------------------+------------------------+------+-------+-----+------+--------+
*/

-- finding out where the thief went to
SELECT *
FROM airports
WHERE id = 4;

/*
+----+--------------+-------------------+---------------+
| id | abbreviation |     full_name     |     city      |
+----+--------------+-------------------+---------------+
| 4  | LGA          | LaGuardia Airport | New York City |
+----+--------------+-------------------+---------------+
*/

-- so the thief went to new york

-- the suspects still remain bruce and diana so from the flight, matching their passport number
SELECT *
FROM passengers
WHERE flight_id = 36
AND passport_number IN (

    SELECT passport_number
    FROM people
    WHERE name = 'Bruce'
    OR name = 'Diana'
);

/*
+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 5773159633      | 4A   | ----> Bruce
+-----------+-----------------+------+
*/

-- the thief is Bruce

-- to find who helped bruce, checking the phone calls made
SELECT *
FROM phone_calls
WHERE month = 7
AND day = 28
AND duration < 60
AND caller IN(

    SELECT phone_number
    FROM people
    WHERE name = 'Bruce'
);

/*
+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
+-----+----------------+----------------+------+-------+-----+----------+
*/

-- now finding who helped bruce by using the above information
SELECT *
FROM people
WHERE phone_number IN (

    SELECT receiver
    FROM phone_calls
    WHERE month = 7
    AND day = 28
    AND duration < 60
    AND caller IN (

        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
);
/*
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 864400 | Robin | (375) 555-8161 | NULL            | 4V16VO0       |
+--------+-------+----------------+-----------------+---------------+
*/

-- so bruce stole the cs50 duck and went to new york city and robin helped him
-- i am batman
