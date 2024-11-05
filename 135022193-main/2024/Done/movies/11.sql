SELECT title FROM movies JOIN stars JOIN ratings
ON movies.id = stars.movie_id AND movies.id = ratings.movie_id
WHERE person_id = (SELECT id FROM people WHERE name = 'Chadwick Boseman') ORDER BY rating DESC LIMIT 5;
