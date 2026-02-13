var date = document.querySelector("#date");
var month = document.querySelector("#month");
var year = document.querySelector("#year");

for (var i = 1; i <= 31; i++) {
  var opt = `<option value=${i}>${i}</option>`;
  date.innerHTML += opt;
}
for (var i = 1; i <= 12; i++) {
  var opt = `<option value=${i}>${i}</option>`;
  month.innerHTML += opt;
}
for (var i = 1940; i <= 2000; i++) {
  var opt = `<option value=${i}>${i}</option>`;
  year.innerHTML += opt;
}

var form = document.querySelector("#form");

form.onsubmit = function () {
  var username = document.querySelector("#username").value;
  var password1 = document.querySelector("#password1").value;
  var repassword1 = document.querySelector("#repassword1").value;
  var password2 = document.querySelector("#password2").value;
  var repassword2 = document.querySelector("#repassword2").value;
  var secuques = document.querySelector("#secuques").value;
  var answer = document.querySelector("#answer").value;
  var fullname = document.querySelector("#fullname").value;
  var gender = document.getElementsByName("gender");
  var email = document.querySelector("#email").value;

  if (!username) {
    alert("User Name can't be empty!");
    return false;
  } else {
    if (!password1) {
      alert("Password level 1 can't be empty");
      return false;
    } else {
      if (!repassword1) {
        alert("Re-enter password level 1 can't be empty");
        return false;
      } else {
        if (password1 != repassword1) {
          alert("Re-enter password level 1 isn't like Password level 1");
          return false;
        } else {
          if (!password2) {
            alert("Password level 2 can't be empty!");
            return false;
          } else {
            if (password2 == password1) {
              alert("Password level 2 can't like Password level 1");
              return false;
            } else {
              if (!repassword2) {
                alert("Re-enter password level 2 can't be empty");
                return false;
              } else {
                if (repassword2 != password2) {
                  alert("Repassword level 2 isn't like password level 2");
                  return false;
                } else {
                  if (secuques == "0") {
                    alert("Security Question must be choose");
                    return false;
                  } else {
                    if (!answer) {
                      alert("Answer can't be empty");
                      return false;
                    } else {
                      if (!fullname) {
                        alert("Full name can't be empty");
                        return false;
                      } else {
                        var count = 0;
                        for (var i = 0; i < gender.length; i++) {
                          if (gender[i].checked === true) {
                            count++;
                          }
                        }
                        if (count == 0) {
                          alert("You must choose your gender");
                          return false;
                        } else {
                          if (!email) {
                            alert("Email can't be empty");
                            return false;
                          } else {
                            var regex =
                              /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
                            if (!regex.test(email)) {
                              alert(
                                "Email must in correct format : userName@domainName"
                              );
                              return false;
                            } else {
                              alert("Register Success!");
                              return true;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
};
