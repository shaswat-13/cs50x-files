-- display the 5 longest songs
SELECT name
FROM songs
ORDER BY duration_ms DESC
LIMIT 5;
