var email = document.querySelector("#email");
var formGroupEmail = email.parentElement;
var messageEmail = formGroupEmail.querySelector(".message-error");
var form = document.querySelector("#form");
var password = document.querySelector("#password");
var formGroupPassword = password.parentElement;
var messagePassword = formGroupPassword.querySelector(".message-error");
email.onblur = function (e) {
  if (email.value === "") {
    formGroupEmail.classList.add("invalid");
    messageEmail.innerText = "Email can't be empty";
  }
  regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
  if (regex.test(email.value)) {
    return true;
  } else {
    formGroupEmail.classList.add("invalid");
    messageEmail.innerText = "Your input don't like email";
  }
};

email.oninput = function (e) {
  formGroupEmail.classList.remove("invalid");
  messageEmail.innerText = "";
};

password.onblur = function (e) {
  if (password.value === "") {
    formGroupPassword.classList.add("invalid");
    messagePassword.innerText = "Password can't be empty ";
  }
  var regex = /([a-z]+)*([A-Z]+)*([1-9]+)*(\~+)*(\@+)*(\#+)*(\$+)*(\?+)/;
  if (regex.test(password.value)) {
    return true;
  } else {
    formGroupPassword.classList.add("invalid");
    messagePassword.innerText = "Password don't invalid ";
  }
};
password.oninput = function (e) {
  formGroupPassword.classList.remove("invalid");
  messagePassword.innerText = "";
};
form.onsubmit = function (e) {
  if (email.value === "") {
    formGroupEmail.classList.add("invalid");
    messageEmail.innerText = "Email can't be empty";
    alert("Email can't be empty");
    return false;
  }
  regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
  if (regex.test(email.value)) {
    return true;
  } else {
    formGroupEmail.classList.add("invalid");
    messageEmail.innerText = "Your input don't like email";
    alert("Your input don't like email");
    return false;
  }
  if (password.value === "") {
    formGroupPassword.classList.add("invalid");
    messagePassword.innerText = "Password can't be empty ";
    alert("Password can't be empty ");
    return false;
  }
  var regex1 = /([a-z]+)*([A-Z]+)*([1-9]+)*(\~+)*(\@+)*(\#+)*(\$+)*(\?+)/;
  if (regex1.test(password.value)) {
    return true;
  } else {
    formGroupPassword.classList.add("invalid");
    messagePassword.innerText = "Password don't invalid ";
    alert("Password don't invalid ");
    return false;
  }
};
