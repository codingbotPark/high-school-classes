const express = require("express");

const { isLoggedIn } = require("../middlewares");
const { follow,unFollow } = require("../controllers/user");

const router = express.Router();

// POST /user/:id/follow
router.post("/:id/follow", isLoggedIn, follow);
router.delete("/:id/follow/:myid", isLoggedIn, unFollow)

module.exports = router;