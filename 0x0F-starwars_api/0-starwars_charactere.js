#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];
const url = `https://swapi.dev/api/films/${movieId}/`;

request(url, async (error, response, body) => {
  if (movieId == null) return;
  if (error) console.log(error);

  for (let i = 0; i < JSON.parse(body).characters.length; i++) {
    await new Promise((resolve, reject) => {
      request(JSON.parse(body).characters[i], function (error, response, body) {
        if (error) console.log(error);
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
