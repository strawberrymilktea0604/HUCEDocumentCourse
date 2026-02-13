const tvEmail = document.formsignin.txtEmail;
const tvPassword = document.formsignin.txtPassword;

//Login button click event
$("#btnLogin").on("click", function () {
    //code here
    //lay ve username va password
    let email = tvEmail.value;
    let password = tvPassword.value;
    if(validateFormData(email, password)){
        handleLogin (email, password);
    }
})

// validate data sign in form
function validateFormData(email, password) {    
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
   // let url = "http://localhost:3000/api/auth/login"

    //khai bao object
    // let req = {
    //     email: email,
    //     password: password
    // }
    // console.log(JSON.stringify(req));
    // var method = "POST";
    // var jsonString = JSON.stringify(req);
    /*
    $.ajax({
        url: url,
        type: method,
        data: jsonString,
        contentType: "application/json; charset=utf-8",
        dataType: "json",
        success: function (response) {
            console.log(response);
            alert("Login success " + response);
            window.location = "home.html";
        },
        error: function (xhr, status, error) {
            // console.log(xhr.responseText);
            console.log(error);
            $("#errMessage").text("Login fail. Please try again.");
        }
    });
    */
        
    // $.post(url, JSON.stringify(req)).done(function (data) {        
    //     alert("Login success " + data);
    //     window.location = "register.html";
    // }).fail(function (data) {
    //     console.log(data);
    //     $("#errMessage").text("Login fail. Please try again.");
    // })
    return true;
    //kiem tra email dung dinh dang tenemail@domain name????

    //goi API phia may chu de kiem tra thong tin

    //Neu dang nhap thanh cong, thi dieu huong ve trang chu


    //nguoc lai thi thong bao loi cho nguoi dung

}

/**
 * Validates whether a given string is in a valid email format.
 *
 * @param {string} value - The string to be validated as an email.
 * @returns {boolean} - Returns `true` if the string is a valid email, otherwise `false`.
 */
function isEmail(value) {
    // Simplified regular expression for email validation
    const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return re.test(String(value).trim());
}
async function handleLogin(email, password) {
    try {
        const response = await fetch("http://localhost:3000/api/auth/login", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({ email, password })
        });

        const data = await response.json();

        if (response.ok) {
            // Store JWT token in local storage
            console.log(data);
            localStorage.setItem("username", data.username); 
            localStorage.setItem("email", data.email);           
            localStorage.setItem("token", data.token);
            // Redirect to homepage
          window.location.href = "add-course.html"; // Change this to your actual homepage
        } else {
            alert(data.message || "Login failed. Please check your credentials.");
        }
    } catch (error) {
        console.error("Error:", error);
        alert("An error occurred. Please try again.");
    }
    
}