SELECT DISTINCT(name) FROM directors JOIN people JOIN ratings
WHERE directors.person_id = people.id AND directors.movie_id = ratings.movie_id AND rating >= 9.0;
