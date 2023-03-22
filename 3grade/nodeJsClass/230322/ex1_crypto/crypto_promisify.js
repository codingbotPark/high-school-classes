const crypto = require('crypto');
const util = require('util');

const getSalt = util.promisify(crypto.randomBytes);
const getKey = util.promisify(crypto.pbkdf2);

async function getPassword(password) {
  try {
    const salt = await getSalt(64);
    const saltStr = salt.toString('base64');
    const key = await getKey(password, salt, 100000, 64, 'sha512');
    const keyStr = key.toString('base64');
    console.log({ salt: saltStr, key: keyStr });
  } catch (err) {
    console.error(err);
  }
}

getPassword('123');
