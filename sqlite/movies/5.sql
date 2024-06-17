-- displays all the harry potter movies in ascending order of their release date
SELECT title, year
FROM movies
WHERE title LIKE 'Harry Potter%'
ORDER BY year;

