SELECT name FROM people JOIN stars JOIN movies
WHERE people.id = stars.person_id AND stars.movie_id = movies.id AND year = '2004'
ORDER BY birth ASC limit 10;
