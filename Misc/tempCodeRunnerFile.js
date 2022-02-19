function getUserById(id) {
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