// Asynchronous Programming

const users = [
  {
    id: 1,
    name: 'A'
  },
  {
    id: 2,
    name: 'B'
  },
  {
    id: 3,
    name: 'C'
  },
  {
    id: 4,
    name: 'D'
  },
  {
    id: 5,
    name: 'E'
  }
];

// function getUserById(id) {
//   console.log('Starting operation...');

//   setTimeout(() => {
//     console.log('Finding user...');

//     const user = users.find((user) => user.id === id);

//     console.log('Operation ended');

//     if (user) {
//       return user;
//     } else {
//       return 'User not found';
//     }
//   }, 1500);
// }

// const user = getUserById(1);
// console.log(user);

// // Callback

// function getUserById(id, cb) {
//   console.log('Starting operation...');

//   setTimeout(() => {
//     console.log('Finding user...');

//     const user = users.find((user) => user.id === id);

//     console.log('Operation ended');

//     if (user) {
//       cb(user);
//     } else {
//       cb('User not found');
//     }
//   }, 1500);
// }

// getUserById(3, (user) => console.log(user));

// Promise

function getUserById(id) {
  return new Promise((resolve, reject) => {
    console.log('Starting operation...');

    setTimeout(() => {
      console.log('Finding user...');

      const user = users.find((user) => user.id === id);

      console.log('Operation ended');

      if (user) {
        resolve(user);
      } else {
        reject('User not found');
      }
    }, 1500);
  });
}

getUserById(3).then((user) => console.log(user));

// Async/Await

async function getUserById(id) {
  return new Promise((resolve, reject) => {
    console.log('Starting operation...');

    setTimeout(() => {
      console.log('Finding user...');

      const user = users.find((user) => user.id === id);

      console.log('Operation ended');

      if (user) {
        resolve(user);
      } else {
        reject('User not found');
      }
    }, 1500);
  });
}

(async () => {
  const user = await getUserById(3);
  console.log(user);
})();

// function finddd(user){
    
// }

// const user = users.find((user) => user.id === id)
// const user = users.find(function(user){user.id === id})

