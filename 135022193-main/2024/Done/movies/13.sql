SELECT name FROM people WHERE id IS NOT (SELECT id FROM people WHERE name = 'Kevin Bacon') AND id
IN (SELECT person_id FROM stars WHERE movie_id IN (SELECT movie_ID FROM stars WHERE person_id =
(SELECT id FROM people WHERE name = 'Kevin Bacon' AND birth = 1958)));

