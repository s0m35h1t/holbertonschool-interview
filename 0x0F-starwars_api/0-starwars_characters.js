#!/usr/bin/node

const request = require('request');

/**
 * Prints all characters of specified Star Wars movie
 */
request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`, async (err, res, body) => {
  if (err) { return console.log(err); }

  const chars = JSON.parse(body).characters;
  for (const c in chars) {
    const res = await new Promise((resolve, reject) => {
      request(chars[c], (err, res, html) => {
        if (err) { reject(err); } else { resolve(JSON.parse(html).name); }
      });
    });
    console.log(res);
  }
});
