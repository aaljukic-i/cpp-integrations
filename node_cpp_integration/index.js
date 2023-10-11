const ffi = require('ffi-napi');
const path = require('path');

const pqxdh = ffi.Library(path.join(__dirname, "../pqxdh-sdk/libencryption.so"), {
    'encrypt': ['string', ['string', 'int']],
});

const message = "Hello World";
const shift = 3;

const encryptedMessage = pqxdh.encrypt(message, shift);
console.log(`${message} => ${encryptedMessage}`);