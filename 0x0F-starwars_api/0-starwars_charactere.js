#!/usr/bin/node

let request = '';
let ident = '';
let url = '';
// The package (request)
package = require('request');
ident = process.argv[2];
// The api of Star wars (you can find it in READMEfile)
url = 'https://swapi-api.hbtn.io/api/films/' + ident;

const myRequest = (url) => {
  return new Promise(function (resolve, reject) {
    package(url, function (error, res, body) {
      if (!error && res.statusCode === 200) {
        resolve(body);
      } else {
        reject(error);
      }
    });
  });
};

const answer = async (url) => {
  let resq = await myRequest(url);
  resq = JSON.parse(resq).characters;
  for (let i = 0; i < resq.length; i++) {
    const resq2 = await myRequest(resq[i]);
    console.log(JSON.parse(resq2).name);
  }
};

answer(url);
