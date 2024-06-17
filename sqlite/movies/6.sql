-- finds the average rating of the movies released in the year 2012
SELECT AVG(ratings.rating)
FROM ratings
JOIN movies ON movies.id = ratings.movie_id
WHERE movies.year = 2012;
