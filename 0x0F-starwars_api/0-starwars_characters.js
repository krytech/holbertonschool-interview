#!/usr/bin/node
const request = require('request');
const filmNum = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + filmNum;

request(url, async (error, response, body) => {
  if (error) {
    console.log(error);
  }
  for (const characterName of JSON.parse(body).characters) {
    await new Promise((resolve, reject) => {
      request(characterName, (error, response, body) => {
        if (error) {
          reject(error);
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
