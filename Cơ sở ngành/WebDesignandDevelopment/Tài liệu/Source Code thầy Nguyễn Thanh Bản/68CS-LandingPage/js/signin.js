const tvEmail = document.formsignin.txtEmail;
const tvPassword = document.formsignin.txtPassword;

// validate data sign in form
function validateFormData() {
    //lay ve username va password
    let email = tvEmail.value;
    let password = tvPassword.value;

    //kiem tra username va password co du lieu hay khong
    if (email == null || email.trim() == "") {
        tvEmail.focus();//dat tro chuot vao truong email
        tvEmail.classList.add("error");
        document.getElementById("errMessage").innerHTML = "Please input your email.";
        // alert('Please input email address.');
        return false;
    } else if (password == null || password.trim() == "") {
        //
        tvEmail.classList.remove("error");
        tvEmail.classList.add("success");
        document.getElementById("errMessage").innerHTML = "";
        //
        tvPassword.classList.add("error");
        document.getElementById("errMessage").innerHTML = "Please input your password";
        tvPassword.focus();
        return false;
    } else if (!isEmail(email)) {
        tvEmail.classList.remove("success");
        tvEmail.classList.add("error");
        ///
        tvPassword.classList.remove("error");
        tvPassword.classList.add("success");
        document.getElementById("errMessage").innerHTML = "Please input a valid email address.";
        tvEmail.focus();//dat tro chuot vao truong email
        return false;
    }
    //
    tvEmail.classList.remove("error");
    tvPassword.classList.remove("error");
    //
    tvEmail.classList.add("success");
    tvPassword.classList.add("success");
    //
    document.getElementById("errMessage").innerHTML = "";
    //kiem tra dinh dang chuan cua email
    // if (email == 'bannguyen@gmail.com' && password == '123456') {
    //     alert('Login success.');
    //     window.location = "register.html";
    // } else {
    //     alert('Login fail.');
    // }
    let url = "https://reqres.in/api/login"
    //khai bao object
    let req = {
        email: email,
        password: password
    }
    $.post(url, req).done(function (data) {
        alert("Login success " + data);
        window.location = "register.html";
    }).fail(function (data) {
        alert(data);
        document.getElementById("errMessage").innerHTML="Login fail. Please try again."
    })
    return true;
    //kiem tra email dung dinh dang tenemail@domain name????

    //goi API phia may chu de kiem tra thong tin

    //Neu dang nhap thanh cong, thi dieu huong ve trang chu


    //nguoc lai thi thong bao loi cho nguoi dung

}
//check valid email
function isEmail(value) {
    //code here
    // Regular expression
    let re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return re.test(String(value).toLowerCase());
}