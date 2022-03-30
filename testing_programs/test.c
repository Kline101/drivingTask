// // Tax calculation
//   for (i = 0; i < no_of_data; i++)
//     {

//       // when car < 5
//       if ((2021 - car[i].year) <= 5)
//     {
//       // when car < 5 and Vol < 1.6L
//       if (car[i].engineVol <= 1.6)
//         {
//           car[i].tax = 150;
//         }
//       // when car < 5 and Vol > 1.6L
//       else
//         {
//           car[i].tax = 300;
//         }

//     }
//       else
//     {

//       // when car < 5 and Vol < 1.4L
//       if (car[i].engineVol <= 1.4)
//         {
//           car[i].tax = 200;
//         }
//       // when car > 5 and Vol is between 1.4-1.6L
//       else if ((car[i].engineVol > 1.4) && (car[i].engineVol <= 1.6))
//         {
//           car[i].tax = 400;
//         }
//       // when car > 5 and Vol > 1.6
//       else if (car[i].engineVol > 1.6)
//         {
//           car[i].tax = 600;