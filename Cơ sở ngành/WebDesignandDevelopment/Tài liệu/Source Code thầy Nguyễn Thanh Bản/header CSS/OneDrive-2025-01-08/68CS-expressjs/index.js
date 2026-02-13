const express = require('express')
const app = express()
const port = 3000
var cors = require('cors');
app.use(express.json());
app.use(cors());
//using jwt
const jwt = require('jsonwebtoken');
//Middleware
app.use('/api/account', (req, res, next) => {
  //lay ve token de kiem tra thong tin.
  const authHeader = req.headers['authorization'];
  console.log(authHeader);
  if (authHeader == null) return res.sendStatus(401)
  const token = authHeader.split(' ')[1];//bearer sdfhsajdfsfhsdkjf
  console.log('Gia tri: ', token);
  //kiem tra token co ton tai hay khong
  if (token == null) return res.sendStatus(401)

  jwt.verify(token, "dhxdhn", (err, user) => {
    if (err) return res.sendStatus(403);
    console.log(user);
    next();
  })
})
//generate a token
function generateAccessToken(username) {
  return jwt.sign(username, "dhxdhn");
}
//search product by search name
app.get('/catalogsearch/result', (req, res) => {
  let query = req.query.q;
  //query trong csdl
  //tra ve ket qua
  console.log(query);
  res.json({
    "products": [
      {
        "id": 1,
        "title": "Essence Mascara Lash Princess",
        "description": "The Essence Mascara Lash Princess is a popular mascara known for its volumizing and lengthening effects. Achieve dramatic lashes with this long-lasting and cruelty-free formula.",
        "category": "beauty",
        "price": 9.99,
        "discountPercentage": 7.17,
        "rating": 4.94,
        "stock": 5,
        "tags": [
          "beauty",
          "mascara"
        ],
        "brand": "Essence",
        "sku": "RCH45Q1A",
        "weight": 2,
        "dimensions": {
          "width": 23.17,
          "height": 14.43,
          "depth": 28.01
        },
        "warrantyInformation": "1 month warranty",
        "shippingInformation": "Ships in 1 month",
        "availabilityStatus": "Low Stock",
        "reviews": [
          {
            "rating": 2,
            "comment": "Very unhappy with my purchase!",
            "date": "2024-05-23T08:56:21.618Z",
            "reviewerName": "John Doe",
            "reviewerEmail": "john.doe@x.dummyjson.com"
          },
          {
            "rating": 2,
            "comment": "Not as described!",
            "date": "2024-05-23T08:56:21.618Z",
            "reviewerName": "Nolan Gonzalez",
            "reviewerEmail": "nolan.gonzalez@x.dummyjson.com"
          },
          {
            "rating": 5,
            "comment": "Very satisfied!",
            "date": "2024-05-23T08:56:21.618Z",
            "reviewerName": "Scarlett Wright",
            "reviewerEmail": "scarlett.wright@x.dummyjson.com"
          }
        ],
        "returnPolicy": "30 days return policy",
        "minimumOrderQuantity": 24,
        "meta": {
          "createdAt": "2024-05-23T08:56:21.618Z",
          "updatedAt": "2024-05-23T08:56:21.618Z",
          "barcode": "9164035109868",
          "qrCode": "..."
        },
        "thumbnail": "...",
        "images": ["...", "...", "..."]
      }
      // 30 items
    ],
    "total": 194,
    "skip": 0,
    "limit": 30
  });
})
//chinh sua thong tin nguoi dung
app.put('/api/account/:id', (req, res) => {
  //edit user
  //lay ve ID nguoi dung
  const id = req.params.id;
  //lay ve thong tin nguoi dung
  const fullname = req.body.fullname;
  const address = req.body.address;
  //code here
})
app.delete('/api/account/:id', (req, res) => {
  const id = req.params.id;
  res.json({
    "msg":"User deleted."
  })
  //delete user
  // xac thuc///
  //1, Kiem tra xem token co ton tai hay khong
  //neu ton tai-> cho xoa
  //neu khong ton tai: ->thong bao loi
})

//them moi thong tin nguoi dung
app.post('/api/user', (req, res) => {
  //code here

})

//API tim kiem thong tin nguoi dung thong qua tu khoa nhap tu o tim kiem
app.get('/api/user/searchbykeyword', (req, res) => {
  //lay ve tu khoa tim kiem
  const value = req.query.keyword;
  console.log(value);
  //truy van trong csdl
  //tra ve json ket qua tim kiem
  res.json({
    "key": "Ket qua tra ve danh sach nguoi dung"
  });
})

app.post('/api/user/login', (req, res) => {
  //check login data from database (using express/nodejs with mongo db)
  var email = req.body.email;//nuce
  console.log(email);
  var password = req.body.password;//123456$@
  //check email va password
  if (email == null || email == "") {
    res.status(400);
    res.json({
      msg: "Email must input."
    })
  } else if (password == null || password == "") {
    res.status(400);
    res.json({
      msg: "Password must input."
    })
  } else {
    // var check = true;//connect to Mongo DB and check username and password is correct or incorrect;
    console.log(email);
    console.log(password);
    //checking user information
    if (email == 'huce@gmail.com' && password == '123456$@') {
      const token = generateAccessToken(email);
      res.json({
        msg: "Login Success.",
        account: {
          name: "Dai hoc xay dung",
          avatar: "john.jpg",
          token: token
        }
      })
    } else {
      res.status(400);
      res.json({
        msg: "Login fail."
      })
    }
  }

})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})