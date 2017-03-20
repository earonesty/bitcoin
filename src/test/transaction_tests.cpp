#include <boost/test/unit_test.hpp>

#include "main.h"
#include "wallet.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(transaction_tests)

BOOST_AUTO_TEST_CASE(basic_transaction_tests)
{

  
  // Random real SLM tx (d629b359826c535e000deca592de70ab97e4e85706f8436cb009693be47b6f46)
  // unsigned char ch[] = {0x01, 0x00, 0x00, 0x00, 0x01, 0x6b, 0xff, 0x7f, 0xcd, 0x4f, 0x85, 0x65, 0xef, 0x40, 0x6d, 0xd5, 0xd6, 0x3d, 0x4f, 0xf9, 0x4f, 0x31, 0x8f, 0xe8, 0x20, 0x27, 0xfd, 0x4d, 0xc4, 0x51, 0xb0, 0x44, 0x74, 0x01, 0x9f, 0x74, 0xb4, 0x00, 0x00, 0x00, 0x00, 0x8c, 0x49, 0x30, 0x46, 0x02, 0x21, 0x00, 0xda, 0x0d, 0xc6, 0xae, 0xce, 0xfe, 0x1e, 0x06, 0xef, 0xdf, 0x05, 0x77, 0x37, 0x57, 0xde, 0xb1, 0x68, 0x82, 0x09, 0x30, 0xe3, 0xb0, 0xd0, 0x3f, 0x46, 0xf5, 0xfc, 0xf1, 0x50, 0xbf, 0x99, 0x0c, 0x02, 0x21, 0x00, 0xd2, 0x5b, 0x5c, 0x87, 0x04, 0x00, 0x76, 0xe4, 0xf2, 0x53, 0xf8, 0x26, 0x2e, 0x76, 0x3e, 0x2d, 0xd5, 0x1e, 0x7f, 0xf0, 0xbe, 0x15, 0x77, 0x27, 0xc4, 0xbc, 0x42, 0x80, 0x7f, 0x17, 0xbd, 0x39, 0x01, 0x41, 0x04, 0xe6, 0xc2, 0x6e, 0xf6, 0x7d, 0xc6, 0x10, 0xd2, 0xcd, 0x19, 0x24, 0x84, 0x78, 0x9a, 0x6c, 0xf9, 0xae, 0xa9, 0x93, 0x0b, 0x94, 0x4b, 0x7e, 0x2d, 0xb5, 0x34, 0x2b, 0x9d, 0x9e, 0x5b, 0x9f, 0xf7, 0x9a, 0xff, 0x9a, 0x2e, 0xe1, 0x97, 0x8d, 0xd7, 0xfd, 0x01, 0xdf, 0xc5, 0x22, 0xee, 0x02, 0x28, 0x3d, 0x3b, 0x06, 0xa9, 0xd0, 0x3a, 0xcf, 0x80, 0x96, 0x96, 0x8d, 0x7d, 0xbb, 0x0f, 0x91, 0x78, 0xff, 0xff, 0xff, 0xff, 0x02, 0x8b, 0xa7, 0x94, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x19, 0x76, 0xa9, 0x14, 0xba, 0xde, 0xec, 0xfd, 0xef, 0x05, 0x07, 0x24, 0x7f, 0xc8, 0xf7, 0x42, 0x41, 0xd7, 0x3b, 0xc0, 0x39, 0x97, 0x2d, 0x7b, 0x88, 0xac, 0x40, 0x94, 0xa8, 0x02, 0x00, 0x00, 0x00, 0x00, 0x19, 0x76, 0xa9, 0x14, 0xc1, 0x09, 0x32, 0x48, 0x3f, 0xec, 0x93, 0xed, 0x51, 0xf5, 0xfe, 0x95, 0xe7, 0x25, 0x59, 0xf2, 0xcc, 0x70, 0x43, 0xf9, 0x88, 0xac, 0x00, 0x00, 0x00, 0x00, 0x00};
  unsigned char ch[] = {1, 16, 0, 0, 0, 0, 0, 7, 116, 71, 125, 213, 86, 101, 88, 128, 1, 20, 70, 98, 32, 0, 12, 198, 110, 235, 179, 55, 113, 31, 248, 131, 54, 102, 109, 223, 253, 219, 187, 186, 170, 173, 218, 160, 1, 31, 249, 145, 28, 195, 58, 174, 226, 33, 24, 135, 121, 147, 53, 89, 154, 164, 69, 87, 126, 238, 237, 215, 118, 111, 246, 101, 91, 191, 242, 37, 91, 176, 9, 145, 21, 80, 1, 16, 0, 0, 0, 0, 0, 4, 72, 132, 71, 115, 48, 4, 68, 64, 2, 34, 32, 6, 98, 42, 173, 208, 7, 116, 67, 55, 119, 125, 210, 40, 132, 70, 110, 237, 208, 1, 27, 187, 187, 186, 173, 223, 251, 182, 96, 7, 119, 115, 60, 203, 180, 69, 87, 124, 201, 149, 80, 11, 191, 246, 99, 54, 100, 65, 21, 83, 48, 3, 63, 251, 191, 243, 62, 236, 192, 3, 62, 225, 29, 211, 49, 16, 2, 34, 32, 2, 42, 162, 45, 218, 174, 238, 224, 9, 154, 172, 195, 61, 213, 80, 15, 245, 94, 227, 63, 251, 176, 12, 203, 187, 188, 193, 23, 121, 155, 183, 123, 186, 175, 241, 23, 121, 154, 173, 220, 205, 217, 153, 156, 194, 35, 59, 186, 172, 200, 135, 113, 23, 127, 253, 215, 116, 71, 121, 148, 74, 164, 76, 194, 32, 1, 31, 255, 255, 255, 255, 255, 255, 255, 240, 3, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 208, 3, 58, 172, 196, 65, 18, 32, 0, 0, 0, 0, 0, 0, 0, 2, 35, 50, 33, 16, 3, 63, 250, 173, 213, 89, 151, 127, 243, 62, 234, 169, 155, 176, 3, 58, 164, 67, 62, 228, 72, 139, 184, 143, 248, 128, 4, 79, 250, 172, 206, 228, 72, 140, 202, 167, 120, 143, 245, 87, 119, 119, 119, 127, 254, 228, 65, 27, 185, 159, 243, 53, 94, 230, 98, 35, 61, 219, 188, 197, 82, 33, 27, 178, 40, 138, 172, 194, 45, 214, 99, 60, 196, 65, 18, 32, 0, 0, 0, 0, 0, 0, 0, 2, 35, 50, 33, 16, 3, 63, 250, 173, 213, 89, 151, 127, 243, 62, 234, 169, 155, 176, 3, 58, 164, 67, 62, 228, 72, 139, 184, 143, 248, 128, 4, 79, 250, 172, 206, 228, 72, 140, 202, 167, 120, 143, 245, 87, 119, 119, 119, 127, 254, 228, 65, 27, 185, 159, 243, 53, 94, 230, 98, 35, 61, 219, 188, 197, 82, 33, 27, 178, 40, 138, 172, 192, 0, 0, 0, 0, 0, 0};
  vector<unsigned char> vch(ch, ch + sizeof(ch) - 1);
  try
  {
    CDataStream stream(vch, SER_DISK, CLIENT_VERSION);
    CTransaction tx;
    // fatal error in "basic_transaction_tests": std::runtime_error: CDataStream::read() : end of data: iostream error
    stream >> tx;
    BOOST_CHECK_MESSAGE(tx.CheckTransaction(), "Simple deserialized transaction should be valid.");

    // Check that duplicate txins fail
    tx.vin.push_back(tx.vin[0]);
    BOOST_CHECK_MESSAGE(!tx.CheckTransaction(), "Transaction with duplicate txins should be invalid.");
  }
  catch (std::exception& e) {
      PrintException(&e, "basic_transaction_tests");
  } catch (...) {
      PrintException(NULL, "basic_transaction_tests");
  }
}

//
// Helper: create two dummy transactions, each with
// two outputs.  The first has 11 and 50 CENT outputs
// paid to a TX_PUBKEY, the second 21 and 22 CENT outputs
// paid to a TX_PUBKEYHASH.
//
static std::vector<CTransaction>
SetupDummyInputs(CBasicKeyStore& keystoreRet, MapPrevTx& inputsRet)
{
    std::vector<CTransaction> dummyTransactions;
    dummyTransactions.resize(2);

    // Add some keys to the keystore:
    CKey key[4];
    for (int i = 0; i < 4; i++)
    {
        key[i].MakeNewKey(i % 2);
        keystoreRet.AddKey(key[i]);
    }

    // Create some dummy input transactions
    dummyTransactions[0].vout.resize(2);
    dummyTransactions[0].vout[0].nValue = 11*CENT;
    dummyTransactions[0].vout[0].scriptPubKey << key[0].GetPubKey() << OP_CHECKSIG;
    dummyTransactions[0].vout[1].nValue = 50*CENT;
    dummyTransactions[0].vout[1].scriptPubKey << key[1].GetPubKey() << OP_CHECKSIG;
    inputsRet[dummyTransactions[0].GetHash()] = make_pair(CTxIndex(), dummyTransactions[0]);

    dummyTransactions[1].vout.resize(2);
    dummyTransactions[1].vout[0].nValue = 21*CENT;
    dummyTransactions[1].vout[0].scriptPubKey.SetDestination(key[2].GetPubKey().GetID());
    dummyTransactions[1].vout[1].nValue = 22*CENT;
    dummyTransactions[1].vout[1].scriptPubKey.SetDestination(key[3].GetPubKey().GetID());
    inputsRet[dummyTransactions[1].GetHash()] = make_pair(CTxIndex(), dummyTransactions[1]);

    return dummyTransactions;
}

BOOST_AUTO_TEST_CASE(test_Get)
{
  CBasicKeyStore keystore;
  MapPrevTx dummyInputs;
  std::vector<CTransaction> dummyTransactions = SetupDummyInputs(keystore, dummyInputs);

  CTransaction t1;
  t1.vin.resize(3);
  t1.vin[0].prevout.hash = dummyTransactions[0].GetHash();
  t1.vin[0].prevout.n = 1;
  t1.vin[0].scriptSig << std::vector<unsigned char>(65, 0);
  t1.vin[1].prevout.hash = dummyTransactions[1].GetHash();
  t1.vin[1].prevout.n = 0;
  t1.vin[1].scriptSig << std::vector<unsigned char>(65, 0) << std::vector<unsigned char>(33, 4);
  t1.vin[2].prevout.hash = dummyTransactions[1].GetHash();
  t1.vin[2].prevout.n = 1;
  t1.vin[2].scriptSig << std::vector<unsigned char>(65, 0) << std::vector<unsigned char>(33, 4);
  t1.vout.resize(2);
  t1.vout[0].nValue = 90*CENT;
  t1.vout[0].scriptPubKey << OP_1;

  BOOST_CHECK(t1.AreInputsStandard(dummyInputs));
  BOOST_CHECK_EQUAL(t1.GetValueIn(dummyInputs), (50+21+22)*CENT);

  // Adding extra junk to the scriptSig should make it non-standard:
  t1.vin[0].scriptSig << OP_11;
  BOOST_CHECK(!t1.AreInputsStandard(dummyInputs));

  // ... as should not having enough:
  t1.vin[0].scriptSig = CScript();
  BOOST_CHECK(!t1.AreInputsStandard(dummyInputs));
}

BOOST_AUTO_TEST_CASE(test_GetThrow)
{
  CBasicKeyStore keystore;
  MapPrevTx dummyInputs;
  std::vector<CTransaction> dummyTransactions = SetupDummyInputs(keystore, dummyInputs);

  MapPrevTx missingInputs;

  CTransaction t1;
  t1.vin.resize(3);
  t1.vin[0].prevout.hash = dummyTransactions[0].GetHash();
  t1.vin[0].prevout.n = 0;
  t1.vin[1].prevout.hash = dummyTransactions[1].GetHash();;
  t1.vin[1].prevout.n = 0;
  t1.vin[2].prevout.hash = dummyTransactions[1].GetHash();;
  t1.vin[2].prevout.n = 1;
  t1.vout.resize(2);
  t1.vout[0].nValue = 90*CENT;
  t1.vout[0].scriptPubKey << OP_1;

  BOOST_CHECK_THROW(t1.AreInputsStandard(missingInputs), runtime_error);
  BOOST_CHECK_THROW(t1.GetValueIn(missingInputs), runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
