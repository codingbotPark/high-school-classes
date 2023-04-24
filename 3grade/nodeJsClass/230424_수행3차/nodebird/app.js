const express = require("express")
const cookieParser = require("cookie-parser")
const morgan = require("morgan")
const path = require("path")
const session = require("express-session")
const nunjucks = require("nunjucks")
const dotenv = require("dotenv")

dotenv.config()
