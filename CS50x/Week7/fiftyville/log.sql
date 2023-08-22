-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Getting first information on crime discription
SELECT id, description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Humphrey Street' AND description LIKE '%CS50%';
-- Gettin a overvriew of the witness iterviews
SELECT name, transcript
FROM interviews
WHERE month = 7 AND day = 28 AND transcript LIKE '%bakery%';



-- narrowing down cars and owners on security log
SELECT *
FROM bakery_security_logs
WHERE month = 7 AND day = 28
AND hour >= 10  AND minute >= 15
AND hour <= 10 AND minute <= 25;
-- looking for the owners of the cars that left the crime scene
SELECT name, people.license_plate, hour, minute, activity
FROM people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE people.license_plate IN
    (SELECT license_plate
    FROM bakery_security_logs
    WHERE month = 7 AND day = 28
    AND hour >= 10  AND minute >= 15
    AND hour <= 10 AND minute <= 25)
    ORDER BY activity;



-- Narrowing down account owners / name from atm transactions
SELECT *
From atm_transactions
WHERE month = 7 AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';
-- look for person id within witdraws
SELECT person_id, name, bank_accounts.account_number, transaction_type, amount, day
FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.account_number IN
    (SELECT account_number
    From atm_transactions
    WHERE month = 7 AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw');
--4 People that left the parking lot and also withdrew money, Bruce, Diana, Iman and Luca



-- Narrowing down calls
SELECT caller, receiver, duration
FROM phone_calls
WHERE month = 7 AND day = 28
AND duration <= 60;
-- names of people who made phonecalls under 60 sec
SELECT name, phone_number
FROM people
WHERE phone_number IN
    (SELECT caller
    FROM phone_calls
    WHERE month = 7 AND day = 28 AND duration < 60);
-- names of people who received phonecalls under 60 sec
SELECT name , phone_number
FROM people
WHERE phone_number IN
    (SELECT receiver
    FROM phone_calls
    WHERE month = 7 AND day = 28
    AND duration < 60);
-- Tables show that Bruce called Robin and Diana called Phillip



-- narrowing down flights for fallowing day, ordered by departure time
SELECT id, destination_airport_id
FROM flights
WHERE month = 7 AND day = 29
ORDER BY hour;
-- checking for passenger names for flights on following day
SELECT name
FROM people
WHERE passport_number IN
    (SELECT passport_number
    FROM passengers
    WHERE flight_id IN (
        SELECT id
        FROM flights
        WHERE month = 7 AND day = 29));

SELECT city
FROM airports
WHERE id =
    (SELECT destination_airport_id
    FROM flights
    WHERE id =
        (SELECT flight_id
        FROM passengers
        WHERE passport_number =
            (SELECT passport_number
            FROM people
            WHERE phone_number IN
                (SELECT receiver
                FROM phone_calls
                WHERE month = 7 AND day = 28
                AND duration < 60
                ))));
-- Passenger Bruce is flying to New York City 