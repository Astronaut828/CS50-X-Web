const menu = document.querySelector('#mobile-menu');
const menuLinks = document.querySelector('.nav-menu');

menu.addEventListener('click', function() {
    menu.classList.toggle('is-active');
    menuLinks.classList.toggle('active');
}) 

// modal items
const modal = document.getElementById('email-modal');
const openBtn = document.querySelector('.main-btn');
const closeBtn = document.querySelector('.close-btn');

// clickevents 
openBtn.addEventListener('click', () => {
    modal.style.display = 'block';
});

closeBtn.addEventListener('click', () => {
    modal.style.display = 'none';
});

window.addEventListener('click', (e) => {
    if(e.target === modal) {
    modal.style.display = 'none';
    }
});

// form validation 
const form = document.getElementById('form');
const name = document.getElementById('name');
const email = document.getElementById('email');
const password = document.getElementById('password');
const passwordConfirm = document.getElementById('password-confirm');

// shoe errror message 
function showError(input, message) {
    const formValidation = input.parentElement;
    formValidation.className = 'form-validation error';

    const errorMessage = formValidation.querySelector('p');
    errorMessage.innerText = message;
}

// show valid 
function showValid(input) {
    const formValidation = input.parentElement;
    formValidation.className = 'form-validation valid';
}

// check required fields 
function checkRequired(inputArr) {
    inputArr.forEach(function(input) {
        if(input.value.trim() === '') {
            showError(input, `${getFieldName(input)} is required`);
        } else {
            showValid(input);
        }
    })   
}

// checking input length
function checkLength(input, min, max) {
    if(input.value.length < min) {
        showError(input, `${getFieldName(input)} must be at least ${min} characters`);
    } else if (input.value.length > max) {
        showError(input, `${getFieldName(input)} must be less then ${max} characters`);
    } else {
        showValid(input);
    }
}

// get fieldname 
function getFieldName(input) {
    return input.name.charAt(0).toUpperCase() + input.name.slice(1);
}


//check password match 
function passwordMatch(input1, input2) {
    if(input1.value !== input2.value) {
        showError(input2, 'Passwords do not match');
    }
}


// email varification for newsletter signup
function isValidEmail(email) {
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return emailRegex.test(email);
  }
  
  // Event listener for form submission
  form.addEventListener('submit', (e) => {
    e.preventDefault(); // Prevent default form submission behavior
  
    // Call the validation functions
    checkRequired([name, email]);
    checkLength(email, 3, 30);
  
    // Validate email address
    if (!isValidEmail(email.value)) {
      showError(email, 'Invalid email address');
    }
  
    // Check if any error messages exist
    if (document.querySelector('.error')) {
      // There are errors, do not submit the form
      return;
    }
  
    // The form is valid, so you can proceed with form submission
    form.submit(); // Submit the form
  });


  function scaleContentBox() {
    var windowHeight = window.innerHeight;
    var hero = document.querySelector('.hero');
    var heroHeight = hero.offsetHeight;
    var contentBox = document.querySelector('.content-box');
    var contentBoxHeight = Math.min(windowHeight * 0.4, heroHeight * 0.4);

    contentBox.style.maxHeight = contentBoxHeight + 'px';
}

// Call the function initially and on window resize
scaleContentBox();
window.addEventListener('resize', scaleContentBox);