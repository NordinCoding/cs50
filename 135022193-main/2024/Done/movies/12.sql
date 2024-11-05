SELECT title FROM movies JOIN stars JOIN people ON
movies.id = stars.movie_id AND stars.person_id = people.id WHERE name = 'Jennifer Lawrence' AND movie_id IN
(SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Bradley Cooper'));
