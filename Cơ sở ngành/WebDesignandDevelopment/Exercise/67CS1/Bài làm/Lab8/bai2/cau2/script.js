var h2Element = document.querySelector('h2');

h2Element.addEventListener('mouseover', function() {
        h2Element.style.color = 'blue';
        h2Element.style.textDecoration = 'none'; // Mất gạch chân
      });

h2Element.addEventListener('mouseout', function() {
        h2Element.style.color = '#333';
        h2Element.style.textDecoration = 'underline'; // Hiện gạch chân lại
      });


function validateForm() {
    // Retrieve form elements
    const nameInput = document.getElementById('name');
    const genderSelect = document.getElementById('gender');
    const passwordInput = document.getElementById('password');
    const confirmPasswordInput = document.getElementById('confirmPassword');
    const telNumberInput = document.getElementById('telNumber');
    const emailInput = document.getElementById('email');
    const ageGroupSelect = document.getElementById('ageGroup');

    // Validate password matching
    if (passwordInput.value !== confirmPasswordInput.value) {
        alert('Sai mat khau');
        return false;
    }

    // Validate email format
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailRegex.test(emailInput.value)) {
        alert('Email khong hop le!');
        return false;
    }

    // Display age group message
    const ageGroupMessage = getAgeGroupMessage(ageGroupSelect.value);
    alert(ageGroupMessage);

    return true;
}

function updateNamePrefix(prefix) {
    var nameInput = document.getElementById('name');
    nameInput.value = `(${prefix}) ${nameInput.value}`;
  }



function getAgeGroupMessage(ageGroup) {
    switch (ageGroup) {
        case 'group1':
            return 'You are in Group 1';
        case 'group2':
            return 'You are in Group 2';
        case 'group3':
            return 'You are in Group 3';
        case 'group4':
            return 'You are in Group 4';
        case 'group5':
            return 'You are in Group 5';
        case 'group6':
            return 'You are in Group 6';
        default:
            return 'Invalid age group';
    }
}
