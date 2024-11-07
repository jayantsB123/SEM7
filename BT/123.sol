pragma solidity >= 0.7.0;

contract Election{

    struct Candidate{
        uint id;
        string name;
        int count;
    }

    mapping(address => bool ) public voters;
    mapping(uint => Candidate ) public cnd;

    uint public CandCnt=0;

    event voterInd(uint indexed candidateId);

    constructor(){
        addCand("Jayant");
        addCand("Pravendra");
    }

    function addCand(string memory name) public payable{
        CandCnt++;
        cnd[CandCnt] = Candidate(CandCnt, name, 0);
    }

    function addVote(uint CandidateID) public{
        require(voters[msg.sender] == false);
        require(CandidateID > 0 && CandidateID <= CandCnt);

        cnd[CandidateID].count++;
        voters[msg.sender]=true;

        emit voterInd(CandidateID);
    }
}