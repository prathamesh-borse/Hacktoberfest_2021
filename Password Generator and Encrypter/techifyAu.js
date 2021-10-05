const crypto = require("crypto");
const Password = require("password-encrypt-util")

const id = crypto.randomBytes(20).toString('hex');
let Password1 = new Password(`${id}`)

let encryptedPassword = Password1.encryptPasswordV2(`${id}`)
console.log(encryptedPassword)

// Generates a Random Password Then Gets Encrypted
// Uses Crypto and https://www.npmjs.com/package/password-encrypt-util

