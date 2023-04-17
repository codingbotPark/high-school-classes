const Sequelize = require('sequelize');

const env = process.env.NODE_ENV || 'development';
const config = require('../config/config')[env]
const db = {};

const sequelize = new Sequelize(config.data)
db.sequelize = sequelize

Module.exports = db;