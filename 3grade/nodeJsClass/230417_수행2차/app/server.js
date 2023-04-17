const app = requir("./app.js")
requir('dotenv').config()

const port = process.env.PORT || 8000
app.listen(port, () => console.log('✅ Server running...'))

