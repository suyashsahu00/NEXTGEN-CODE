const { ethers } = require("hardhat");

async function main() {
  console.log("Deploying NFTMinter contract...");

  // Get the deployer account
  const [deployer] = await ethers.getSigners();
  console.log("Deploying contracts with the account:", deployer.address);
  console.log("Account balance:", (await deployer.provider.getBalance(deployer.address)).toString());

  // Deploy the contract
  const NFTMinter = await ethers.getContractFactory("NFTMinter");
  const nftMinter = await NFTMinter.deploy(deployer.address);

  await nftMinter.waitForDeployment();

  const contractAddress = await nftMinter.getAddress();
  console.log("NFTMinter deployed to:", contractAddress);

  // Save the contract address and ABI for the frontend
  const fs = require("fs");
  const contractsDir = "./app/contracts";

  if (!fs.existsSync(contractsDir)) {
    fs.mkdirSync(contractsDir, { recursive: true });
  }

  fs.writeFileSync(
    contractsDir + "/contract-address.json",
    JSON.stringify({ NFTMinter: contractAddress }, undefined, 2)
  );

  const NFTMinterArtifact = await hre.artifacts.readArtifact("NFTMinter");

  fs.writeFileSync(
    contractsDir + "/NFTMinter.json",
    JSON.stringify(NFTMinterArtifact, null, 2)
  );

  console.log("Contract address and ABI saved to app/contracts/");
}

main()
  .then(() => process.exit(0))
  .catch((error) => {
    console.error(error);
    process.exit(1);
  });
