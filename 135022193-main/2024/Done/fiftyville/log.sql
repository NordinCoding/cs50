-- Keep a log of any SQL queries you execute as you solve the mystery.

-- query to look for all reports that happened on the day of the crime
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28 LIMIT 10;

-- query to look for all bakery security records from the day of the crime
SELECT * FROM bakery_security_logs WHERE month = 7 AND day = 28;

-- Checking information from specific license plates to see any suspicous behaviour
SELECT * FROM bakery_security_logs WHERE license_plate = '13FNH73';
SELECT * FROM bakery_security_logs WHERE license_plate = 'R3G7486';

-- Finding the interviews from the day of the crime
SELECT * FROM interviews WHERE month = 7 AND day = 28;

-- Finding all ATM logs from the day of the crime on Leggett Street of type withdraw
SELECT * FROM atm_transactions WHERE month = 7 AND day = 28 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street';

-- Finding all phone calls from the day of the crime where the duration was less than a minute
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60;

-- Getting a log of all flights happening on the day after the crime ordered by time
SELECT * FROM flights WHERE month = 7 AND day = 29 ORDER BY hour;

-- Get a list of all people with the same phonenumbers that were seen in the phone calls query
-- and the same license plates that were seen in the bakery sec. logs query
-- and are on the earliest flight from the 29th of July
-- and their bank accounts where in the records of the leggett street withdrawls

SELECT * FROM people WHERE id IN
    (SELECT person_id FROM bank_accounts WHERE person_id IN
    (SELECT id FROM people WHERE phone_number IN
    (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60) AND
    license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28) AND
    passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36))));



-- getting a list of the receivers of the phone calls of the 2 current suspects
    SELECT * FROM people WHERE phone_number IN
        (SELECT receiver
            FROM phone_calls
            WHERE month = 7 AND day = 28 AND duration < 60 AND caller IN
        (SELECT phone_number FROM people WHERE id IN
        (SELECT person_id FROM bank_accounts WHERE person_id IN
        (SELECT id FROM people WHERE phone_number IN
        (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60) AND
        license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28) AND
        passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36)))));
